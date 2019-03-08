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
    ana::output_ttreex = create_ttreex();

    // Add outputs to TTreeX
    add_bdt_ttreex_outputs();
    add_misc_ttreex_outputs();

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
    ana::cutflow.addCutToLastActiveCut("CutTrigger" ,
            [&]()
            {
                return
                hww.HLT_Ele27_WPLoose_Gsf()                       || 
                hww.HLT_Ele30_WPLoose_Gsf()                       || 
                hww.HLT_Ele45_WPLoose_Gsf()                       || 
                hww.HLT_Ele105_CaloIdVT_GsfTrkIdT()               || 
                hww.HLT_Ele115_CaloIdVT_GsfTrkIdT()               || 
                hww.HLT_IsoTkMu24()                               || 
                hww.HLT_IsoMu24()                                 || 
                hww.HLT_SingleMu50()                              || 
                hww.HLT_SingleEl40()                              || 
                hww.HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165()       || 
                hww.HLT_Mu50()                                    || 
                hww.HLT_TkMu50()                                  || 
                hww.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50()         || 
                hww.HLT_AK8PFJet360_TrimMass30()                  || 
                hww.HLT_PFHT800()                                 || 
                hww.HLT_PFHT900()                                 || 
                hww.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5()          || 
                hww.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5()          || 
                hww.HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20();
            } , UNITY);
    ana::cutflow.addCutToLastActiveCut("CutBVeto" , [&]() { return hww.nbmed() == 0; } , UNITY );
    ana::cutflow.addCutToLastActiveCut("CutNLep" , [&]() { return hww.L_p4().pt() > 0 and fabs(hww.L_dxy()) < 0.01; } , UNITY );
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
                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had", [&]()
                        {
                            return (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() < 0)
                                    and
                                    (hww.HLT_IsoTkMu24()                               || 
                                     hww.HLT_IsoMu24()                                 || 
                                     hww.HLT_Mu50()                                    || 
                                     hww.HLT_TkMu50()                                  || 
                                     hww.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50()         || 
                                     hww.HLT_AK8PFJet360_TrimMass30()                  || 
                                     hww.HLT_PFHT800()                                 || 
                                     hww.HLT_PFHT900()                                 || 
                                     hww.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5()          || 
                                     hww.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5()          || 
                                     hww.HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20());
                        }, UNITY);
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
                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep", [&]()
                        {
                            return (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() > 0)
                                    and (hww.HLT_TkMu50() or hww.HLT_Mu50());
                        }, UNITY);
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

        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadSubjetPt", [&]() { return hww.J_softdropPuppiSubjet1_pt() > 20 and hww.J_softdropPuppiSubjet2_pt() > 20.; }, UNITY);
        // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadNPFcands", [&]() { return hww.J_npfcands() < 65; }, UNITY);
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

    // Object multiplicities
    ana::histograms.addHistogram("nj"        ,  10 ,     0 ,   10 , [&]() { return hww.nj();                                             } );
    ana::histograms.addHistogram("nb"        ,   4 ,     0 ,    4 , [&]() { return hww.nb();                                             } );
    ana::histograms.addHistogram("nbmed"     ,   4 ,     0 ,    4 , [&]() { return hww.nbmed();                                          } );
    ana::histograms.addHistogram("nbtight"   ,   4 ,     0 ,    4 , [&]() { return hww.nbtight();                                        } );
    ana::histograms.addHistogram("nak8jets"  ,   6 ,     0 ,    6 , [&]() { return hww.nak8jets();                                       } );
    ana::histograms.addHistogram("nrecolep"  ,   4 ,     0 ,    4 , [&]() { return hww.nrecolep();                                       } );

    // Object kinematics
    ana::histograms.addHistogram("ak8_pt0"   , 180 ,     0 , 1000 , [&]() { return hww.ak8jets_p4().size() > 0 ? hww.ak8jets_p4()[0].pt() : -999;                       } );
    ana::histograms.addHistogram("ak8_pt1"   , 180 ,     0 , 1000 , [&]() { return hww.ak8jets_p4().size() > 1 ? hww.ak8jets_p4()[1].pt() : -999;                       } );
    ana::histograms.addHistogram("L_pt"      , 180 ,     0 ,  600 , [&]() { return hww.L_p4().pt();                                                                     } );
    ana::histograms.addHistogram("L_eta"     , 180 ,    -3 ,    3 , [&]() { return hww.L_p4().eta();                                                                    } );
    ana::histograms.addHistogram("L_abseta"  , 180 ,     0 ,    3 , [&]() { return fabs(hww.L_p4().eta());                                                              } );
    ana::histograms.addHistogram("J_pt"      , 180 ,     0 , 1000 , [&]() { return hww.J_p4().pt();                                                                     } );
    ana::histograms.addHistogram("J_eta"     , 180 ,    -5 ,    5 , [&]() { return hww.J_p4().eta();                                                                    } );
    ana::histograms.addHistogram("H_pt"      , 180 ,     0 , 1000 , [&]() { return hww.H_p4().pt();                                                                     } );
    ana::histograms.addHistogram("H_eta"     , 180 ,    -5 ,    5 , [&]() { return hww.H_p4().eta();                                                                    } );
    ana::histograms.addHistogram("QQ_pt"     , 180 ,     0 , 1000 , [&]() { return hww.QQ_p4().pt();                                                                    } );
    ana::histograms.addHistogram("QQ_eta"    , 180 ,    -5 ,    5 , [&]() { return hww.QQ_p4().eta();                                                                   } );
    ana::histograms.addHistogram("V_pt"      , 180 ,     0 , 1000 , [&]() { return hww.V_p4().pt();                                                                     } );
    ana::histograms.addHistogram("V_eta"     , 180 ,    -5 ,    5 , [&]() { return hww.V_p4().eta();                                                                    } );
    ana::histograms.addHistogram("R_pt"      , 180 ,     0 , 1000 , [&]() { return hww.Recoil_p4().pt();                                                                } );
    ana::histograms.addHistogram("R_eta"     , 180 ,    -5 ,    5 , [&]() { return hww.Recoil_p4().eta();                                                               } );
    ana::histograms.addHistogram("met_pt"    , 180 ,     0 ,  600 , [&]() { return hww.met_pt();                                                                        } );
    ana::histograms.addHistogram("Lmet_pt"   , 180 ,     0 ,  600 , [&]() { return hww.Lmet_p4().pt();                                                                  } );

    // Lepton property
    ana::histograms.addHistogram("L_ip3d"    , 180 ,    -1 ,    1 , [&]() { return hww.L_ip3d();                                                                        } );
    ana::histograms.addHistogram("L_sip3d"   , 180 ,     0 ,   10 , [&]() { return fabs(hww.L_ip3d() / hww.L_ip3derr());                                                } );
    ana::histograms.addHistogram("L_dxy"     , 180 ,    -1 ,    1 , [&]() { return hww.L_dxy();                                                                         } );
    ana::histograms.addHistogram("L_dz"      , 180 ,    -1 ,    1 , [&]() { return hww.L_dz();                                                                          } );
    ana::histograms.addHistogram("L_absip3d" , 180 ,     0 ,  0.1 , [&]() { return fabs(hww.L_ip3d());                                                                  } );
    ana::histograms.addHistogram("L_absdxy"  , 180 ,     0 , 0.05 , [&]() { return fabs(hww.L_dxy());                                                                   } );
    ana::histograms.addHistogram("L_absdz"   , 180 ,     0 ,  0.1 , [&]() { return fabs(hww.L_dz());                                                                    } );
    ana::histograms.addHistogram("L_mini"    , 180 ,     0 ,  0.2 , [&]() { return hww.L_miniIsoEA();                                                                   } );
    ana::histograms.addHistogram("L_03EA"    , 180 ,     0 ,    1 , [&]() { return hww.L_relIso03EA();                                                                  } );
    ana::histograms.addHistogram("L_04DB"    , 180 ,     0 ,    1 , [&]() { return hww.L_relIso04DB();                                                                  } );

    // Fat-jet property
    ana::histograms.addHistogram("J_nJettinessTau21"             , 180 ,   0 ,   1 , [&]() { return hww.J_nJettinessTau2() / hww.J_nJettinessTau1()             ;} );
    ana::histograms.addHistogram("J_nJettinessTau31"             , 180 ,   0 ,   1 , [&]() { return hww.J_nJettinessTau3() / hww.J_nJettinessTau1()             ;} );
    ana::histograms.addHistogram("J_nJettinessTau32"             , 180 ,   0 ,   1 , [&]() { return hww.J_nJettinessTau3() / hww.J_nJettinessTau2()             ;} );
    ana::histograms.addHistogram("J_nJettinessTau1"              , 180 ,   0 ,   1 , [&]() { return hww.J_nJettinessTau1()                                      ;} );
    ana::histograms.addHistogram("J_nJettinessTau2"              , 180 ,   0 ,   1 , [&]() { return hww.J_nJettinessTau2()                                      ;} );
    ana::histograms.addHistogram("J_nJettinessTau3"              , 180 ,   0 ,   1 , [&]() { return hww.J_nJettinessTau3()                                      ;} );
    ana::histograms.addHistogram("J_deep_rawdisc_h4q"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_h4q()                                    ;} );
    ana::histograms.addHistogram("J_deep_rawdisc_hbb"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_hbb()                                    ;} );
    ana::histograms.addHistogram("J_deep_rawdisc_qcd"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_qcd()                                    ;} );
    ana::histograms.addHistogram("J_deep_rawdisc_top"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_top()                                    ;} );
    ana::histograms.addHistogram("J_deep_rawdisc_w"              , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_w()                                      ;} );
    ana::histograms.addHistogram("J_deep_rawdisc_z"              , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_z()                                      ;} );
    ana::histograms.addHistogram("J_deep_rawdisc_zbb"            , 180 ,   0 ,   1 , [&]() { return hww.J_deep_rawdisc_zbb()                                    ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet1_pt"     , 180 ,   0 , 600 , [&]() { return hww.J_softdropPuppiSubjet1_pt()                             ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet1_eta"    , 180 ,  -5 ,   5 , [&]() { return hww.J_softdropPuppiSubjet1_eta()                            ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet1_phi"    , 180 ,  -5 ,   5 , [&]() { return hww.J_softdropPuppiSubjet1_phi()                            ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet1_mass"   , 180 ,  -5 ,  80 , [&]() { return hww.J_softdropPuppiSubjet1_mass()                           ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet1_energy" , 180 ,  -5 , 900 , [&]() { return hww.J_softdropPuppiSubjet1_energy()                         ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet2_pt"     , 180 ,   0 , 450 , [&]() { return hww.J_softdropPuppiSubjet2_pt()                             ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet2_eta"    , 180 ,  -5 ,   5 , [&]() { return hww.J_softdropPuppiSubjet2_eta()                            ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet2_phi"    , 180 ,  -5 ,   5 , [&]() { return hww.J_softdropPuppiSubjet2_phi()                            ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet2_mass"   , 180 ,  -5 ,  40 , [&]() { return hww.J_softdropPuppiSubjet2_mass()                           ;} );
    ana::histograms.addHistogram("J_softdropPuppiSubjet2_energy" , 180 ,  -5 , 600 , [&]() { return hww.J_softdropPuppiSubjet2_energy()                         ;} );
    ana::histograms.addHistogram("J_npfcands"                    , 100 ,   0 , 100 , [&]() { return hww.J_npfcands()                                            ;} );

    // Masses
    ana::histograms.addHistogram("mQQ"       , 180 ,     0 ,  300 , [&]() { return hww.QQ_p4().mass();                                                                                                                                                                                                            } );
    ana::histograms.addHistogram("mV"        , 180 ,     0 ,  300 , [&]() { return hww.V_p4().mass();                                                                                                                                                                                                             } );
    ana::histograms.addHistogram("mJ"        , 180 ,     0 ,  300 , [&]() { return hww.J_p4().mass();                                                                                                                                                                                                             } );
    ana::histograms.addHistogram("mJ_SD"     , 180 ,     0 ,  300 , [&]() { return hww.J_softdropMass();                                                                                                                                                                                                          } );
    ana::histograms.addHistogram("mRecoil"   , 180 ,     0 , 1000 , [&]() { return hww.Recoil_p4().mass();                                                                                                                                                                                                        } );
    ana::histograms.addHistogram("RecoH_max" , 180 ,     0 , 1000 , [&]() { return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() > (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass(); } );
    ana::histograms.addHistogram("RecoH_min" , 180 ,     0 , 1000 , [&]() { return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() < (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass(); } );
    ana::histograms.addHistogram("mDmax"     , 180 ,     0 , 1000 ,
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
    ana::histograms.addHistogram("mDmin"     , 180 ,     0 , 1000 ,
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
                return mD1 > mD2 ? mD2 : mD1;
            });
    ana::histograms.addHistogram("mQQ_SD"     , 180 , 0    , 300 , [&]()
            {
                LV J_SD = RooUtil::Calc::getLV(hww.J_p4().pt(), hww.J_p4().eta(), hww.J_p4().phi(), hww.J_softdropMass());
                return RooUtil::Calc::DeltaR(J_SD, hww.L_p4()) < 0.8 ? (J_SD - hww.L_p4()).mass() : J_SD.mass() ;
            } );
    ana::histograms.addHistogram("mQQ_SDv2"   , 180 , 0    , 300 , [&]()
            {
                LV J_SD = RooUtil::Calc::getLV(hww.J_p4().pt(), hww.J_p4().eta(), hww.J_p4().phi(), hww.J_softdropMass());
                return (J_SD - hww.L_p4()).mass() > 0 ? (J_SD - hww.L_p4()).mass() : J_SD.mass() ;
            } );
    ana::histograms.addHistogram("mWLmax", 180, 0, 300, [&]()
            {
                LV Lv1 = hww.L_p4() + hww.neu_p4_sol1();
                LV Lv2 = hww.L_p4() + hww.neu_p4_sol2();
                float m1 = Lv1.mass();
                float m2 = Lv2.mass();
                return m1 > m2 ? m1 : m2;
            } );
    ana::histograms.addHistogram("mWLmin", 180, 0, 300, [&]()
            {
                LV Lv1 = hww.L_p4() + hww.neu_p4_sol1();
                LV Lv2 = hww.L_p4() + hww.neu_p4_sol2();
                float m1 = Lv1.mass();
                float m2 = Lv2.mass();
                return m1 > m2 ? m2 : m1;
            } );
    ana::histograms.addHistogram("mLsubjet_max", 180, 0, 300, [&]()
            {
                LV subjet1 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(), hww.J_softdropPuppiSubjet1_eta(), hww.J_softdropPuppiSubjet1_phi(), hww.J_softdropPuppiSubjet1_mass());
                LV subjet2 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(), hww.J_softdropPuppiSubjet2_eta(), hww.J_softdropPuppiSubjet2_phi(), hww.J_softdropPuppiSubjet2_mass());
                float m1 = (hww.L_p4() + subjet1).mass();
                float m2 = (hww.L_p4() + subjet2).mass();
                return m1 > m2 ? m1 : m2;
            } );
    ana::histograms.addHistogram("mLsubjet_min", 180, 0, 300, [&]()
            {
                LV subjet1 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(), hww.J_softdropPuppiSubjet1_eta(), hww.J_softdropPuppiSubjet1_phi(), hww.J_softdropPuppiSubjet1_mass());
                LV subjet2 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(), hww.J_softdropPuppiSubjet2_eta(), hww.J_softdropPuppiSubjet2_phi(), hww.J_softdropPuppiSubjet2_mass());
                float m1 = (hww.L_p4() + subjet1).mass();
                float m2 = (hww.L_p4() + subjet2).mass();
                return m1 > m2 ? m2 : m1;
            } );

    // Correlations
    ana::histograms.addHistogram("dr_L_QQ"    , 180 ,     0 ,      4 , [&]() { return hww.dr_L_QQ();                                                                       } );
    ana::histograms.addHistogram("deltaFrac"  , 180 ,    -2 ,      2 , [&]() { return hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt(); } );
    ana::histograms.addHistogram("mRatio"     , 180 ,     0 ,      4 , [&]() { return hww.V_p4().mass() / hww.J_p4().mass();                                               } );
    ana::histograms.addHistogram("mRatio_SD"  , 180 ,     0 ,      4 , [&]() { return hww.V_softdropMass() / hww.J_softdropMass();                                         } );
    ana::histograms.addHistogram("dphiRJ"     , 180 ,     0 , 3.1416 , [&]() { return fabs(RooUtil::Calc::DeltaPhi(hww.Recoil_p4(), hww.J_p4()));                          } );

    ana::histograms.addHistogram("detaLsubjet_max", 180, 0, 4, [&]()
            {
                LV subjet1 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(), hww.J_softdropPuppiSubjet1_eta(), hww.J_softdropPuppiSubjet1_phi(), hww.J_softdropPuppiSubjet1_mass());
                LV subjet2 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(), hww.J_softdropPuppiSubjet2_eta(), hww.J_softdropPuppiSubjet2_phi(), hww.J_softdropPuppiSubjet2_mass());
                float m1 = (hww.L_p4() + subjet1).mass();
                float m2 = (hww.L_p4() + subjet2).mass();
                float deta1 = fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), subjet1));
                float deta2 = fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), subjet2));
                return m1 > m2 ? deta1 : deta2;
            } );
    ana::histograms.addHistogram("detaLsubjet_min", 180, 0, 4, [&]()
            {
                LV subjet1 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(), hww.J_softdropPuppiSubjet1_eta(), hww.J_softdropPuppiSubjet1_phi(), hww.J_softdropPuppiSubjet1_mass());
                LV subjet2 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(), hww.J_softdropPuppiSubjet2_eta(), hww.J_softdropPuppiSubjet2_phi(), hww.J_softdropPuppiSubjet2_mass());
                float m1 = (hww.L_p4() + subjet1).mass();
                float m2 = (hww.L_p4() + subjet2).mass();
                float deta1 = fabs(RooUtil::Calc::DeltaEta(hww.L_p4(), subjet1));
                float deta2 = fabs(RooUtil::Calc::DeltaEta(hww.L_p4(), subjet2));
                return m1 > m2 ? deta2 : deta1;
            } );
    ana::histograms.addHistogram("dphiLsubjet_max", 180, 0, 3.1416, [&]()
            {
                LV subjet1 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(), hww.J_softdropPuppiSubjet1_eta(), hww.J_softdropPuppiSubjet1_phi(), hww.J_softdropPuppiSubjet1_mass());
                LV subjet2 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(), hww.J_softdropPuppiSubjet2_eta(), hww.J_softdropPuppiSubjet2_phi(), hww.J_softdropPuppiSubjet2_mass());
                float m1 = (hww.L_p4() + subjet1).mass();
                float m2 = (hww.L_p4() + subjet2).mass();
                float dphi1 = fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), subjet1));
                float dphi2 = fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), subjet2));
                return m1 > m2 ? dphi1 : dphi2;
            } );
    ana::histograms.addHistogram("dphiLsubjet_min", 180, 0, 3.1416, [&]()
            {
                LV subjet1 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(), hww.J_softdropPuppiSubjet1_eta(), hww.J_softdropPuppiSubjet1_phi(), hww.J_softdropPuppiSubjet1_mass());
                LV subjet2 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(), hww.J_softdropPuppiSubjet2_eta(), hww.J_softdropPuppiSubjet2_phi(), hww.J_softdropPuppiSubjet2_mass());
                float m1 = (hww.L_p4() + subjet1).mass();
                float m2 = (hww.L_p4() + subjet2).mass();
                float dphi1 = fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), subjet1));
                float dphi2 = fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), subjet2));
                return m1 > m2 ? dphi2 : dphi1;
            } );
    ana::histograms.addHistogram("drLsubjet_max", 180, 0, 5, [&]()
            {
                LV subjet1 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(), hww.J_softdropPuppiSubjet1_eta(), hww.J_softdropPuppiSubjet1_phi(), hww.J_softdropPuppiSubjet1_mass());
                LV subjet2 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(), hww.J_softdropPuppiSubjet2_eta(), hww.J_softdropPuppiSubjet2_phi(), hww.J_softdropPuppiSubjet2_mass());
                float m1 = (hww.L_p4() + subjet1).mass();
                float m2 = (hww.L_p4() + subjet2).mass();
                float dr1 = RooUtil::Calc::DeltaR(hww.L_p4(), subjet1);
                float dr2 = RooUtil::Calc::DeltaR(hww.L_p4(), subjet2);
                return m1 > m2 ? dr1 : dr2;
            } );
    ana::histograms.addHistogram("drLsubjet_min", 180, 0, 5, [&]()
            {
                LV subjet1 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(), hww.J_softdropPuppiSubjet1_eta(), hww.J_softdropPuppiSubjet1_phi(), hww.J_softdropPuppiSubjet1_mass());
                LV subjet2 = RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(), hww.J_softdropPuppiSubjet2_eta(), hww.J_softdropPuppiSubjet2_phi(), hww.J_softdropPuppiSubjet2_mass());
                float m1 = (hww.L_p4() + subjet1).mass();
                float m2 = (hww.L_p4() + subjet2).mass();
                float dr1 = RooUtil::Calc::DeltaR(hww.L_p4(), subjet1);
                float dr2 = RooUtil::Calc::DeltaR(hww.L_p4(), subjet2);
                return m1 > m2 ? dr2 : dr1;
            } );

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
RooUtil::TTreeX util::create_ttreex()
{
    ana::output_ttree = new TTree("t", "t");
    RooUtil::TTreeX tx(ana::output_ttree);

    return tx;

}


//_____________________________________________________________________________
void util::add_bdt_ttreex_outputs()
{
    ana::output_ttreex.createBranch<float>("wgt");

    ana::output_ttreex.createBranch<float>("QQ_pt");
    ana::output_ttreex.createBranch<float>("QQ_mass");
    ana::output_ttreex.createBranch<float>("J_pt");
    ana::output_ttreex.createBranch<float>("J_mass");

    ana::output_ttreex.createBranch<float>("dr_L_QQ");
    ana::output_ttreex.createBranch<float>("dr_L_J");

    ana::output_ttreex.createBranch<float>("met_pt");

    ana::output_ttreex.createBranch<float>("Lmet_pt");
    ana::output_ttreex.createBranch<float>("Lmet_mass");
    ana::output_ttreex.createBranch<float>("Lmet_mt");
    ana::output_ttreex.createBranch<float>("LQQ_mass");

    ana::output_ttreex.createBranch<float>("RecoH_mass_minsol12");

    ana::output_ttreex.createBranch<float>("L_pt");
    ana::output_ttreex.createBranch<float>("L_relIso03EA");
    ana::output_ttreex.createBranch<float>("L_relIso04DB");
    ana::output_ttreex.createBranch<float>("L_miniIsoEA");
    ana::output_ttreex.createBranch<float>("L_customrelIso005EA");
    ana::output_ttreex.createBranch<float>("L_customrelIso010EA");

    ana::output_ttreex.createBranch<float>("recoil_pt");
    ana::output_ttreex.createBranch<float>("isrbalance");

    ana::output_ttreex.createBranch<float>("mljreg");
    ana::output_ttreex.createBranch<float>("mljak4");
    ana::output_ttreex.createBranch<float>("dphilj");
    ana::output_ttreex.createBranch<float>("drlj");
    ana::output_ttreex.createBranch<float>("detalj");

    ana::output_ttreex.createBranch<float>("J_softdropMass");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau1");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau2");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau3");
    ana::output_ttreex.createBranch<float>("J_deep_rawdisc_h4q");
    ana::output_ttreex.createBranch<float>("J_deep_rawdisc_hbb");
    ana::output_ttreex.createBranch<float>("J_deep_rawdisc_qcd");
    ana::output_ttreex.createBranch<float>("J_deep_rawdisc_top");
    ana::output_ttreex.createBranch<float>("J_deep_rawdisc_w");
    ana::output_ttreex.createBranch<float>("J_deep_bindisc_w");
    ana::output_ttreex.createBranch<float>("J_deep_rawdisc_z");
    ana::output_ttreex.createBranch<float>("J_deep_rawdisc_zbb");
    ana::output_ttreex.createBranch<float>("J_softdropPuppiSubjet1_pt");
    ana::output_ttreex.createBranch<float>("J_softdropPuppiSubjet1_eta");
    ana::output_ttreex.createBranch<float>("J_softdropPuppiSubjet1_mass");
    ana::output_ttreex.createBranch<float>("J_softdropPuppiSubjet2_pt");
    ana::output_ttreex.createBranch<float>("J_softdropPuppiSubjet2_eta");
    ana::output_ttreex.createBranch<float>("J_softdropPuppiSubjet2_mass");
    ana::output_ttreex.createBranch<float>("J_npfcands");
    ana::output_ttreex.createBranch<float>("J_partonFlavour");

    ana::output_ttreex.createBranch<float>("BDT_v1_0");
    ana::output_ttreex.createBranch<float>("BDT_v1_1");
    ana::output_ttreex.createBranch<float>("BDT_v1_2");
    ana::output_ttreex.createBranch<float>("BDT_v1_3");
    ana::output_ttreex.createBranch<float>("BDT_v1_4");
    ana::output_ttreex.createBranch<float>("BDT_v1_5");
    ana::output_ttreex.createBranch<float>("BDT_v1_6");
    ana::output_ttreex.createBranch<float>("BDT_v1_7");
    ana::output_ttreex.createBranch<float>("BDT_v1_8");
    ana::output_ttreex.createBranch<float>("BDT_v1_9");
    ana::output_ttreex.createBranch<float>("BDT_v1_10");
    ana::output_ttreex.createBranch<float>("BDT_v1_11");
    ana::output_ttreex.createBranch<float>("BDT_v1_12");
    ana::output_ttreex.createBranch<float>("BDT_v1_13");
    ana::output_ttreex.createBranch<float>("BDT_v1_14");
    ana::output_ttreex.createBranch<float>("BDT_v1_15");
    ana::output_ttreex.createBranch<float>("BDT_v1_16");
    ana::output_ttreex.createBranch<float>("BDT_v1_17");

    ana::output_ttreex.createBranch<float>("BDT_v2_0");
    ana::output_ttreex.createBranch<float>("BDT_v2_1");
    ana::output_ttreex.createBranch<float>("BDT_v2_2");
    ana::output_ttreex.createBranch<float>("BDT_v2_3");
    ana::output_ttreex.createBranch<float>("BDT_v2_4");
    ana::output_ttreex.createBranch<float>("BDT_v2_5");
    ana::output_ttreex.createBranch<float>("BDT_v2_6");
    ana::output_ttreex.createBranch<float>("BDT_v2_7");
    ana::output_ttreex.createBranch<float>("BDT_v2_8");
    ana::output_ttreex.createBranch<float>("BDT_v2_9");
    ana::output_ttreex.createBranch<float>("BDT_v2_10");
    ana::output_ttreex.createBranch<float>("BDT_v2_11");
    ana::output_ttreex.createBranch<float>("BDT_v2_12");
}

//_____________________________________________________________________________
void util::add_misc_ttreex_outputs()
{
    ana::output_ttreex.createBranch<float>("ak8_lepton_subtraction_dpt");
    ana::output_ttreex.createBranch<float>("ak8_lepton_subtraction_dr");
    ana::output_ttreex.createBranch<float>("ak8_lepton_subtraction_id");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_dpt_wrt_miniaod");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_dpt_wrt_miniaod");
    ana::output_ttreex.createBranch<float>("ak8_miniaod_softdropMass");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_softdropMass");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_softdropMass");
    ana::output_ttreex.createBranch<float>("ak8_miniaod_softdropSubjetDR");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_softdropSubjetDR");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_softdropSubjetDR");
}


//_____________________________________________________________________________
void util::run_jet_clustering()
{
    if (ana::cutflow.getCut("CutISR400MuMinus").pass)
    {
        fastjet::ClusterSequence cs_w_lep = cluster_jets(get_particles(false), 0.8);
        fastjet::ClusterSequence cs_wo_lep = cluster_jets(get_particles(true), 0.8);
        fastjet::PseudoJet sd_jet_w_lep = get_softdrop_jet(cs_w_lep);
        fastjet::PseudoJet sd_jet_wo_lep = get_softdrop_jet(cs_wo_lep);

        std::vector<fastjet::PseudoJet> jets_w_lep = fastjet::sorted_by_pt(cs_w_lep.inclusive_jets());
        std::vector<fastjet::PseudoJet> jets_wo_lep = fastjet::sorted_by_pt(cs_wo_lep.inclusive_jets());

        float miniaod_pt = (hww.J_p4() * hww.J_undoJEC()).pt();
        float recl_w_lep_pt = jets_w_lep[0].pt();
        float recl_wo_lep_pt = jets_wo_lep[0].pt();

        ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_dpt_wrt_miniaod", miniaod_pt - recl_w_lep_pt);
        ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_dpt_wrt_miniaod", miniaod_pt - recl_wo_lep_pt);

        ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_softdropMass", sd_jet_w_lep.m());
        ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_softdropMass", sd_jet_wo_lep.m());
        ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_softdropSubjetDR", sd_jet_w_lep.structure_of<fastjet::contrib::SoftDrop>().delta_R());
        ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_softdropSubjetDR", sd_jet_wo_lep.structure_of<fastjet::contrib::SoftDrop>().delta_R());

        ana::output_ttreex.setBranch<float>("ak8_miniaod_softdropMass", hww.J_softdropMass());
        ana::output_ttreex.setBranch<float>("ak8_miniaod_softdropSubjetDR",
                RooUtil::Calc::DeltaR(
                    RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(),hww.J_softdropPuppiSubjet1_eta(),hww.J_softdropPuppiSubjet1_phi(),hww.J_softdropPuppiSubjet1_mass()),
                    RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(),hww.J_softdropPuppiSubjet2_eta(),hww.J_softdropPuppiSubjet2_phi(),hww.J_softdropPuppiSubjet2_mass())
                    )
                );
    }
}

//__________________________________________________________________________________________________
// Do clusterinng where the input: particles is a list of Pseudo jets (constituents such as PF or calo clusters etc.)
// Perofrom Anti-kt clustering on vector of PseudoJets (probably a PF candidate list)
fastjet::ClusterSequence util::cluster_jets(std::vector<fastjet::PseudoJet> particles, double R)
{
    // choose a jet definition
    fastjet::JetDefinition jet_def(fastjet::antikt_algorithm, R);

    // run the clustering, extract the jets
    fastjet::ClusterSequence cs(particles, jet_def);
    std::vector<fastjet::PseudoJet> jets = fastjet::sorted_by_pt(cs.inclusive_jets());

#ifdef DEBUG
    // print out some infos
    std::cout << "Clustering with " << jet_def.description() << std::endl;

    // print the jets
    std::cout <<   "        pt y phi" << std::endl;
    for (unsigned i = 0; i < jets.size(); i++)
    {

        std::cout << "jet " << i << ": "<< jets[i].pt() << " " << jets[i].rap() << " " << jets[i].phi() << std::endl;

        std::vector<fastjet::PseudoJet> constituents = jets[i].constituents();

        for (unsigned j = 0; j < constituents.size(); j++)
        {
            std::cout << "    constituent " << j << "'s pt: " << constituents[j].pt() << std::endl;
        }
    }
#endif

    return cs;
}

//----------------------------------------------------------------------
/// overloaded jet info output
std::ostream & operator<<(std::ostream & ostr, const fastjet::PseudoJet & jet) 
{
    if (jet == 0)
    {
        ostr << " 0 ";
    }
    else
    {
        ostr << " pt = " << jet.pt()
            << " m = " << jet.m()
            << " y = " << jet.rap()
            << " phi = " << jet.phi();
    }
    return ostr;
}

//__________________________________________________________________________________________________
// Get a vector of pseudojets with PF candidates
std::vector<fastjet::PseudoJet> util::get_particles(bool subtract_lepton)
{
    std::vector<fastjet::PseudoJet> particles;

    // Htag_pf_p4 contains the pf candidates around the fat-jet candidate
    // For a puppi jet reclustering, pf candidates are weighted by each weight

    for (unsigned int ipf = 0; ipf < hww.Htag_pf_p4().size(); ++ipf)
    {
        float puppi_wgt = hww.Htag_pf_puppi_wgt()[ipf];

        if (puppi_wgt == 0)
            continue;

        if (subtract_lepton)
        {
            float dr = RooUtil::Calc::DeltaR(hww.Htag_pf_p4()[ipf], hww.L_p4());
            if (dr < 0.1 and hww.Htag_pf_id()[ipf] == hww.L_id())
            {
                ana::output_ttreex.setBranch<float>("ak8_lepton_subtraction_dpt", hww.Htag_pf_p4()[ipf].pt() - hww.L_p4().pt());
                ana::output_ttreex.setBranch<float>("ak8_lepton_subtraction_dr", dr);
                ana::output_ttreex.setBranch<float>("ak8_lepton_subtraction_id", hww.Htag_pf_id()[ipf]);
                continue;
            }
        }
        LV pf = hww.Htag_pf_p4()[ipf] * puppi_wgt;

        float px = pf.px();
        float py = pf.py();
        float pz = pf.pz();
        float E  = pf.energy();
        particles.push_back(fastjet::PseudoJet(px, py, pz, E));
    }

    return particles;
}

//__________________________________________________________________________________________________
// Perform SoftDrop grooming and return the groomed PseudoJet
fastjet::PseudoJet util::get_softdrop_jet(fastjet::ClusterSequence cs)
{
    // give the soft drop groomer a short name
    // Use a symmetry cut z > z_cut R^beta
    // By default, there is no mass-drop requirement
    double z_cut = 0.10;
    double beta  = 2.0;
    fastjet::contrib::SoftDrop sd(beta, z_cut);

    std::vector<fastjet::PseudoJet> jets = fastjet::sorted_by_pt(cs.inclusive_jets());

#ifdef DEBUG
    cout << "SoftDrop groomer is: " << sd.description() << endl;
#endif

    // Run SoftDrop and examine the output
    fastjet::PseudoJet sd_jet = sd(jets[0]);

#ifdef DEBUG
    cout << endl;
    cout << "original    jet: " << jets[0] << endl;
    cout << "SoftDropped jet: " << sd_jet << endl;

    assert(sd_jet != 0); //because soft drop is a groomer (not a tagger), it should always return a soft-dropped jet

    cout << "  delta_R between subjets: " << sd_jet.structure_of<fastjet::contrib::SoftDrop>().delta_R() << endl;
    cout << "  symmetry measure(z):     " << sd_jet.structure_of<fastjet::contrib::SoftDrop>().symmetry() << endl;
    cout << "  mass drop(mu):           " << sd_jet.structure_of<fastjet::contrib::SoftDrop>().mu() << endl;
#endif

    return sd_jet;

    // for (unsigned ijet = 0; ijet < jets.size(); ijet++) {
    //     // Run SoftDrop and examine the output
    //     fastjet::PseudoJet sd_jet = sd(jets[ijet]);
    //     cout << endl;
    //     cout << "original    jet: " << jets[ijet] << endl;
    //     cout << "SoftDropped jet: " << sd_jet << endl;

    //     assert(sd_jet != 0); //because soft drop is a groomer (not a tagger), it should always return a soft-dropped jet

    //     cout << "  delta_R between subjets: " << sd_jet.structure_of<fastjet::contrib::SoftDrop>().delta_R() << endl;
    //     cout << "  symmetry measure(z):     " << sd_jet.structure_of<fastjet::contrib::SoftDrop>().symmetry() << endl;
    //     cout << "  mass drop(mu):           " << sd_jet.structure_of<fastjet::contrib::SoftDrop>().mu() << endl;
    // }
}
