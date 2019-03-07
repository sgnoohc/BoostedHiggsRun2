#include "utility.h"

//_____________________________________________________________________________
void util::parse_arguments(int argc, char** argv)
{

    cxxopts::Options options("\n  $ doAnalysis",  "\n********************************\n*                              *\n* Run 2 Boosted Higgs Analysis *\n*                              *\n********************************\n");

    options.add_options()
        ("i,input", "Comma separated input file list", cxxopts::value<std::string>())
        ("o,output", "Output file name", cxxopts::value<std::string>())
        ("n,nevents", "N events to loop over", cxxopts::value<int>()->default_value("-1"))
        ("t,test", "Run test job. i.e. overrides output option to 'test.root' and 'recreate's the file.")
        ("H,hist", "Book histogram")
        ("C,cutflow", "Book cutflows")
        ("T,tree", "write ttree")
        ("h,help", "Print help")
        ;

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    if (result.count("nevents"))
    {
        ana::n_events = result["nevents"].as<int>();
    }

    if (result.count("input"))
    {
        ana::input_file_list_tstring = result["input"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input list is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    if (result.count("test"))
    {
        ana::output_tfile = new TFile("test.root", "recreate");
    }
    else
    {
        if (result.count("output"))
        {
            ana::output_tfile = new TFile(result["output"].as<std::string>().c_str(), "create");
            if (not ana::output_tfile->IsOpen())
            {
                std::cout << options.help() << std::endl;
                std::cout << "ERROR: output already exists! provide new output name or delete old file. OUTPUTFILE=" << result["output"].as<std::string>() << std::endl;
                exit(1);
            }
        }
        else
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: Output file name is not provided! Check your arguments" << std::endl;
            exit(1);
        }
    }

    if (result.count("hist"))
    {
        ana::do_histograms = true;
    }
    else
    {
        ana::do_histograms = false;
    }

    if (result.count("cutflow"))
    {
        ana::do_cutflow = true;
    }
    else
    {
        ana::do_cutflow = false;
    }

    if (result.count("tree"))
    {
        ana::write_ttree = true;
    }
    else
    {
        ana::write_ttree = false;
    }

    std::cout <<  "=========================================================" << std::endl;
    std::cout <<  " Setting of the analysis job based on provided arguments " << std::endl;
    std::cout <<  "---------------------------------------------------------" << std::endl;
    std::cout <<  " ana::input_file_list_tstring: " << ana::input_file_list_tstring <<  std::endl;
    std::cout <<  " ana::output_tfile: " << ana::output_tfile->GetName() <<  std::endl;
    std::cout <<  " ana::n_events: " << ana::n_events <<  std::endl;
    std::cout <<  "=========================================================" << std::endl;

    return;

}

//_____________________________________________________________________________
void util::initialize_analysis()
{

    // Create main TChain
    ana::main_tchain = RooUtil::FileUtil::createTChain("t", ana::input_file_list_tstring);

    // Initialize looper
    ana::looper.init(ana::main_tchain, &hww, ana::n_events);

    // Create TTreeX
    ana::output_ttreex = create_bdt_ttreex();

    // Cutflow utility object that creates a tree structure of cuts
    // Need to set the output file in order to book histograms
    ana::cutflow.setTFile(ana::output_tfile);

    return;

}

//_____________________________________________________________________________
void util::set_cuts()
{

    // Basic weight cuts
    ana::cutflow.addCut("CutWeight",
            [&]()
            {
                if (ana::input_file_list_tstring.Contains("WJetsToLNu_TuneCUETP8M1"))
                    return hww.gen_ht() < 400.;
                else
                    return true;
            },
            [&]()
            {
                return hww.evt_scale1fb() * 35.9;
            });
    ana::cutflow.addCutToLastActiveCut("CutBVeto" , [&]() { return hww.nbmed() == 0; } , UNITY );
    ana::cutflow.addCutToLastActiveCut("CutNLep" , [&]() { return hww.L_p4().pt() > 0; } , UNITY );
    ana::cutflow.addCutToLastActiveCut("CutNAK8" , [&]() { return hww.J_p4().pt() > 0; } , UNITY );

    //_____________________________________________________________________________
    // Some nested loops to create various cut regions with shorter lines of code
    // std::vector<TString> ISRbins = {"200", "200to300", "300", "300to400", "400", "400to450", "450", "450to500", "500", "500to600", "600"};
    // std::vector<TString> ISRbins = {"200", "300", "400", "450", "500", "600"};
    // std::vector<TString> ISRbins = {"300", "400", "500", "600"};
    std::vector<TString> ISRbins = {"400"};
    std::vector<TString> LeptonChannels = {"El", "Mu"};
    std::vector<TString> Charges = {"Plus", "Minus"};

    for (auto& ISRbin : ISRbins)
    {
        std::vector<TString> ISRbinsLiteral;
        // If the ISRbin literal expression contains "to" (e.g. 400to450) then define upper and lower cut
        if (ISRbin.Contains("to"))
        {
            ISRbinsLiteral = RooUtil::StringUtil::split(ISRbin, "to");
        }
        // Otherwise go from lower cut to very large number cut
        else
        {
            ISRbinsLiteral.push_back(ISRbin);
            ISRbinsLiteral.push_back("999999999");
        }
        float lowISRbin  = ISRbinsLiteral[0].Atof(); // lower cut
        float highISRbin = ISRbinsLiteral[1].Atof(); // upper cut
        ana::cutflow.getCut("CutNAK8");
        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin, [=]() { return hww.Recoil_p4().pt() > lowISRbin and hww.Recoil_p4().pt() < highISRbin; }, UNITY);
        for (auto& lepton : LeptonChannels)
        {
            ana::cutflow.getCut("CutISR"+ISRbin);
            if (lepton.EqualTo("El"))
                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton, [&]() { return abs(hww.L_id())==11; }, UNITY);
            else
                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton, [&]() { return abs(hww.L_id())==13; }, UNITY);
            for (auto& charge : Charges)
            {
                ana::cutflow.getCut("CutISR"+ISRbin+lepton);

                if (lepton.EqualTo("El"))
                {
                    if (charge.EqualTo("Plus"))
                        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge, [&]() { return hww.L_id()==-11;}, UNITY );
                    else
                        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge, [&]() { return hww.L_id()== 11;}, UNITY );
                }
                else if (lepton.EqualTo("Mu"))
                {
                    if (charge.EqualTo("Plus"))
                        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge, [&]() { return hww.L_id()==-13;}, UNITY );
                    else
                        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge, [&]() { return hww.L_id()== 13;}, UNITY );
                }

                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge);
                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"GenHad", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() : 1; }, UNITY);
                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge);
                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"GenLep", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() : 1; }, UNITY);

                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge);
                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had", [&]() { return (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() < 0); }, UNITY);
                {
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenHad", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() : 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenLep", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() : 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenHadOff", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() < 60.: 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenLepOff", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() < 60. : 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenHadOn", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() >= 60. : 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenLepOn", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() >= 60. : 1; }, UNITY);
                }
                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge);
                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep", [&]() { return hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() > 0; }, UNITY);
                {
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenHad", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() : 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenLep", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() : 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenHadOff", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() < 60.: 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenLepOff", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() < 60. : 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenHadOn", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() >= 60. : 1; }, UNITY);
                    ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenLepOn", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() >= 60. : 1; }, UNITY);
                }
            }
        }
    }

    //_____________________________________________________________________________
    // Some strawman selections to each of the channel for study
    for (auto& ISRbin : ISRbins)
    {
        // CutMuMinusHad
        ana::cutflow.getCut("CutISR"+ISRbin+"MuMinusHad");
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut1", [&]() { return (hww.dr_L_QQ() < 0.8)                           ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return (hww.J_softdropMass() > 20.)                    ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)       ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut4", [&]() { return hww.QQ_p4().mass() > 65. and hww.QQ_p4().mass() < 100.; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut5", [&]() { return hww.L_customrelIso005EA() < 1.2                 ;}, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut6", [&]() { return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4()).mass() < 170;}, UNITY);

        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut1", [&]() { return hww.QQ_p4().mass() < 95. and hww.QQ_p4().mass() > 70.; }, UNITY);
        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return ((hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() < (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass()) < 180; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut3", [&]() { return hww.J_softdropMass() > 80; }, UNITY);
        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut4", [&]() { return hww.L_customrelIso005EA() < 1.12; }, UNITY);
        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut5", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.); }, UNITY);
        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut6", [&]() { return (hww.J_near_ak4jets_p4().size() > 0 ? fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), hww.J_near_ak4jets_p4()[0])) : -999) < 0.4; }, UNITY);

        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut1", [&]() { return hww.J_softdropMass() > 15. and hww.J_softdropMass() < 108; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return (hww.J_mass() < 130.)                    ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut3", [&]() { return hww.L_customrelIso005EA() < 1.12                 ;}, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut4", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 154.)       ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut5", [&]() { return ((hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() < (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass()) < 200.; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut6", [&]() { return hww.Recoil_p4().pt() / (hww.J_p4().pt() + hww.met_pt()) - 1; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut7", [&]() { return hww.QQ_p4().mass() > 70. and hww.QQ_p4().mass() < 100.; }, UNITY);

        // CutMuPlusHad
        ana::cutflow.getCut("CutISR"+ISRbin+"MuPlusHad");
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut1", [&]() { return (hww.dr_L_QQ() < 0.8)                            ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut2", [&]() { return (hww.J_softdropMass() > 20.)                     ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)        ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut4", [&]() { return hww.QQ_p4().mass() > 65. and hww.QQ_p4().mass() < 100.; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut5", [&]() { return hww.L_customrelIso005EA() < 1.2                  ;}, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut6", [&]() { return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4()).mass() < 170;}, UNITY);

        // CutMuMinusLep
        ana::cutflow.getCut("CutISR"+ISRbin+"MuMinusLep");
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut1", [&]() { return (hww.dr_L_QQ() > 0.12)                          ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut2", [&]() { return (hww.J_npfcands() > 15)                         ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)       ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut4", [&]() { return (hww.J_softdropMass() > 20)                     ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut5", [&]() { return (hww.J_deep_rawdisc_qcd() < 0.5)                ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut6", [&]() { return (hww.L_relIso03EA() > 0.2)                      ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut7", [&]() { return (hww.L_miniIsoEA() < 0.04)                      ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut8", [&]() { return (hww.J_deep_rawdisc_w() > 0.1)                  ; }, UNITY);

        // CutMuPlusLep
        ana::cutflow.getCut("CutISR"+ISRbin+"MuPlusLep");
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut1", [&]() { return (hww.dr_L_QQ() > 0.12)                           ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut2", [&]() { return (hww.J_npfcands() > 15)                          ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)        ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut4", [&]() { return (hww.J_softdropMass() > 20)                      ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut5", [&]() { return (hww.J_deep_rawdisc_qcd() < 0.3)                 ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut6", [&]() { return (hww.L_relIso03EA() > 0.2)                       ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut7", [&]() { return (hww.L_miniIsoEA() < 0.04)                       ; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut8", [&]() { return (hww.J_deep_rawdisc_w() > 0.1)                   ; }, UNITY);
    }

}

//_____________________________________________________________________________
void util::create_histograms()
{
    //_____________________________________________________________________________
    // Histogram defintiions
    ana::histograms.addHistogram("L_pt"      , 180 ,     0 ,  600 , [&]() { return hww.L_p4().pt();   } );
    ana::histograms.addHistogram("L_eta"     , 180 ,    -3 ,    3 , [&]() { return hww.L_p4().eta();  } );
    ana::histograms.addHistogram("J_pt"      , 180 ,     0 , 1000 , [&]() { return hww.J_p4().pt();   } );
    ana::histograms.addHistogram("J_eta"     , 180 ,    -5 ,    5 , [&]() { return hww.J_p4().eta();  } );
    ana::histograms.addHistogram("H_pt"      , 180 ,     0 , 1000 , [&]() { return hww.H_p4().pt();   } );
    ana::histograms.addHistogram("H_eta"     , 180 ,    -5 ,    5 , [&]() { return hww.H_p4().eta();  } );
    ana::histograms.addHistogram("QQ_pt"     , 180 ,     0 ,  600 , [&]() { return hww.QQ_p4().pt();  } );
    ana::histograms.addHistogram("QQ_eta"    , 180 ,    -5 ,    5 , [&]() { return hww.QQ_p4().eta(); } );
    ana::histograms.addHistogram("deltaFrac" , 180 ,    -2 ,    2 , [&]() { return hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt(); } );
    ana::histograms.addHistogram("mDmax"     , 180 ,     0 ,  600 ,
            [&]()
            {
                LV Lv1 = hww.L_p4() + hww.neu_p4_sol1();
                LV Lv2 = hww.L_p4() + hww.neu_p4_sol2();
                float DR1 = RooUtil::Calc::DeltaR(Lv1, hww.QQ_p4());
                float DR2 = RooUtil::Calc::DeltaR(Lv2, hww.QQ_p4());
                float Pt1 = (Lv1 + hww.QQ_p4()).pt();
                float Pt2 = (Lv2 + hww.QQ_p4()).pt();
                float mD1 = DR1 * Pt1 / 2.;
                float mD2 = DR2 * Pt2 / 2.;
                return mD1 > mD2 ? mD1 : mD2;
            });
    ana::histograms.addHistogram("mDmin"     , 180 ,     0 ,  600 ,
            [&]()
            {
                LV Lv1 = hww.L_p4() + hww.neu_p4_sol1();
                LV Lv2 = hww.L_p4() + hww.neu_p4_sol2();
                float DR1 = RooUtil::Calc::DeltaR(Lv1, hww.QQ_p4());
                float DR2 = RooUtil::Calc::DeltaR(Lv2, hww.QQ_p4());
                float Pt1 = (Lv1 + hww.QQ_p4()).pt();
                float Pt2 = (Lv2 + hww.QQ_p4()).pt();
                float mD1 = DR1 * Pt1 / 2.;
                float mD2 = DR2 * Pt2 / 2.;
                return mD1 > mD2 ? mD1 : mD2;
            });
}

//_____________________________________________________________________________
void util::book_histograms()
{
    if (ana::do_cutflow)
        ana::cutflow.bookCutflows();

    if (ana::do_histograms)
        ana::cutflow.bookHistograms(ana::histograms);
}

//_____________________________________________________________________________
void util::run_analysis()
{
    // Print cut structure before starting the loop just to visually see it
    ana::cutflow.printCuts();

    // Looping input file
    while (ana::looper.nextEvent())
    {
        ana::cutflow.fill();
    }

    // Writing output file
    ana::cutflow.saveOutput();

    // Writing TTree output to TFile
    if (ana::write_ttree)
        ana::output_ttreex.save(ana::output_tfile);

}


//_____________________________________________________________________________
RooUtil::TTreeX util::create_bdt_ttreex()
{
    ana::output_ttree = new TTree("t", "t");
    RooUtil::TTreeX tx(ana::output_ttree);

    tx.createBranch<float>("wgt");

    tx.createBranch<float>("QQ_pt");
    tx.createBranch<float>("QQ_mass");
    tx.createBranch<float>("J_pt");
    tx.createBranch<float>("J_mass");

    tx.createBranch<float>("dr_L_QQ");
    tx.createBranch<float>("dr_L_J");

    tx.createBranch<float>("met_pt");

    tx.createBranch<float>("Lmet_pt");
    tx.createBranch<float>("Lmet_mass");
    tx.createBranch<float>("Lmet_mt");
    tx.createBranch<float>("LQQ_mass");

    tx.createBranch<float>("RecoH_mass_minsol12");

    tx.createBranch<float>("L_pt");
    tx.createBranch<float>("L_relIso03EA");
    tx.createBranch<float>("L_relIso04DB");
    tx.createBranch<float>("L_miniIsoEA");
    tx.createBranch<float>("L_customrelIso005EA");
    tx.createBranch<float>("L_customrelIso010EA");

    tx.createBranch<float>("recoil_pt");
    tx.createBranch<float>("isrbalance");

    tx.createBranch<float>("mljreg");
    tx.createBranch<float>("mljak4");
    tx.createBranch<float>("dphilj");
    tx.createBranch<float>("drlj");
    tx.createBranch<float>("detalj");

    tx.createBranch<float>("J_softdropMass");
    tx.createBranch<float>("J_nJettinessTau1");
    tx.createBranch<float>("J_nJettinessTau2");
    tx.createBranch<float>("J_nJettinessTau3");
    tx.createBranch<float>("J_deep_rawdisc_h4q");
    tx.createBranch<float>("J_deep_rawdisc_hbb");
    tx.createBranch<float>("J_deep_rawdisc_qcd");
    tx.createBranch<float>("J_deep_rawdisc_top");
    tx.createBranch<float>("J_deep_rawdisc_w");
    tx.createBranch<float>("J_deep_bindisc_w");
    tx.createBranch<float>("J_deep_rawdisc_z");
    tx.createBranch<float>("J_deep_rawdisc_zbb");
    tx.createBranch<float>("J_softdropPuppiSubjet1_pt");
    tx.createBranch<float>("J_softdropPuppiSubjet1_eta");
    tx.createBranch<float>("J_softdropPuppiSubjet1_mass");
    tx.createBranch<float>("J_softdropPuppiSubjet2_pt");
    tx.createBranch<float>("J_softdropPuppiSubjet2_eta");
    tx.createBranch<float>("J_softdropPuppiSubjet2_mass");
    tx.createBranch<float>("J_npfcands");
    tx.createBranch<float>("J_partonFlavour");

    tx.createBranch<float>("BDT_v1_0");
    tx.createBranch<float>("BDT_v1_1");
    tx.createBranch<float>("BDT_v1_2");
    tx.createBranch<float>("BDT_v1_3");
    tx.createBranch<float>("BDT_v1_4");
    tx.createBranch<float>("BDT_v1_5");
    tx.createBranch<float>("BDT_v1_6");
    tx.createBranch<float>("BDT_v1_7");
    tx.createBranch<float>("BDT_v1_8");
    tx.createBranch<float>("BDT_v1_9");
    tx.createBranch<float>("BDT_v1_10");
    tx.createBranch<float>("BDT_v1_11");
    tx.createBranch<float>("BDT_v1_12");
    tx.createBranch<float>("BDT_v1_13");
    tx.createBranch<float>("BDT_v1_14");
    tx.createBranch<float>("BDT_v1_15");
    tx.createBranch<float>("BDT_v1_16");
    tx.createBranch<float>("BDT_v1_17");

    tx.createBranch<float>("BDT_v2_0");
    tx.createBranch<float>("BDT_v2_1");
    tx.createBranch<float>("BDT_v2_2");
    tx.createBranch<float>("BDT_v2_3");
    tx.createBranch<float>("BDT_v2_4");
    tx.createBranch<float>("BDT_v2_5");
    tx.createBranch<float>("BDT_v2_6");
    tx.createBranch<float>("BDT_v2_7");
    tx.createBranch<float>("BDT_v2_8");
    tx.createBranch<float>("BDT_v2_9");
    tx.createBranch<float>("BDT_v2_10");
    tx.createBranch<float>("BDT_v2_11");
    tx.createBranch<float>("BDT_v2_12");

    return tx;

}
