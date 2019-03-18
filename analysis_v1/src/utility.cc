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
        ("study_reclustering", "study reclustering of the jets")
        ("make_slim_ttree", "make slim ttree")
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

    // Among the following options only one can be turned on
    if (result.count("study_reclustering") + result.count("make_slim_ttree") <= 1)
    {
        if (result.count("study_reclustering"))
        {
            ana::study_reclustering = true;
        }
        else
        {
            ana::study_reclustering = false;
        }
        if (result.count("make_slim_ttree"))
        {
            ana::make_slim_ttree = true;
        }
        else
        {
            ana::make_slim_ttree = false;
        }
    }
    else
    {
        std::cout << "ERROR:" << std::endl;
        std::cout << "Among the following options only one can be turned on!" << std::endl;
        std::cout << "More than one is detected!" << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "study_reclustering : turned on ? " << result.count("study_reclustering") << std::endl;
        std::cout << "make_slim_ttree : turned on ? " << result.count("make_slim_ttree") << std::endl;
        exit(1);
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
    add_ttreex_outputs();

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
                return 1;
                // return
                // hww.HLT_Ele27_WPLoose_Gsf()                       || 
                // hww.HLT_Ele30_WPLoose_Gsf()                       || 
                // hww.HLT_Ele45_WPLoose_Gsf()                       || 
                // hww.HLT_Ele105_CaloIdVT_GsfTrkIdT()               || 
                // hww.HLT_Ele115_CaloIdVT_GsfTrkIdT()               || 
                // hww.HLT_IsoTkMu24()                               || 
                // hww.HLT_IsoMu24()                                 || 
                // hww.HLT_SingleMu50()                              || 
                // hww.HLT_SingleEl40()                              || 
                // hww.HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165()       || 
                // hww.HLT_Mu50()                                    || 
                // hww.HLT_TkMu50()                                  || 
                // hww.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50()         || 
                // hww.HLT_AK8PFJet360_TrimMass30()                  || 
                // hww.HLT_PFHT800()                                 || 
                // hww.HLT_PFHT900()                                 || 
                // hww.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5()          || 
                // hww.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5()          || 
                // hww.HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20();
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
                                    (
                                     hww.HLT_Mu50()                                    || 
                                     hww.HLT_TkMu50()                                  || 
                                     hww.HLT_IsoMu24()                                 || 
                                     hww.HLT_IsoTkMu24()                               || 
                                     hww.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50()         || 
                                     hww.HLT_AK8PFJet360_TrimMass30()                  || 
                                     hww.HLT_PFHT800()                                 || 
                                     hww.HLT_PFHT900()                                 || 
                                     hww.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5()          || 
                                     hww.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5()          || 
                                     hww.HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20())
                                    ;
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
                                    and (hww.HLT_TkMu50() or hww.HLT_Mu50())
                                    and (hww.L_p4().pt() > 52.);
                                    ;
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
        ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut1", [&]() { return (hww.dr_L_QQ() > 0.12)                          ; }, UNITY);
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
        if (ana::study_reclustering)
            run_study_reclustering();
        else if (ana::make_slim_ttree)
            make_slim_ttree();
    }

    // Writing output file
    ana::cutflow.saveOutput();

    // Writing TTree output to TFile
    if (ana::study_reclustering)
        ana::output_ttreex.save(ana::output_tfile);
    else if (ana::make_slim_ttree)
        ana::output_ttreex.save(ana::output_tfile);

}


//_____________________________________________________________________________
RooUtil::TTreeX util::create_ttreex()
{
    if (ana::make_slim_ttree)
        ana::output_ttree = ana::main_tchain->CloneTree(0);
        // ana::output_ttree = new TTree("t", "t");
    else if (ana::study_reclustering)
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
void util::add_reclustering_study_ttreex_outputs()
{
    ana::output_ttreex.createBranch<float>("wgt");

    ana::output_ttreex.createBranch<float>("gen_q0_pt");
    ana::output_ttreex.createBranch<float>("gen_q1_pt");
    ana::output_ttreex.createBranch<float>("gen_dr_qq");
    ana::output_ttreex.createBranch<float>("gen_mass_qq");
    ana::output_ttreex.createBranch<float>("gen_mass_lqq");
    ana::output_ttreex.createBranch<float>("deltaFrac");
    ana::output_ttreex.createBranch<float>("gen_whad_pt");
    ana::output_ttreex.createBranch<float>("gen_wlep_pt");

    ana::output_ttreex.createBranch<float>("ak8_lepton_subtraction_dpt");
    ana::output_ttreex.createBranch<float>("ak8_lepton_subtraction_dr");
    ana::output_ttreex.createBranch<float>("ak8_lepton_subtraction_id");

    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_dpt_wrt_miniaod");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_deta_wrt_miniaod");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_dphi_wrt_miniaod");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_dmass_wrt_miniaod");

    ana::output_ttreex.createBranch<float>("ak8_miniaod_softdropMass");
    ana::output_ttreex.createBranch<float>("ak8_miniaod_mass");

    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_mass");
    ana::output_ttreex.createBranch<float>("ak6_reclustered_wo_lepton_mass");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_mass");
    ana::output_ttreex.createBranch<float>("ak12_reclustered_wo_lepton_mass");
    ana::output_ttreex.createBranch<float>("ak15_reclustered_wo_lepton_mass");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_nopuppi_mass");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_ca_mass");

    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_softdropMass");
    ana::output_ttreex.createBranch<float>("ak6_reclustered_wo_lepton_softdropMass");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_softdropMass");
    ana::output_ttreex.createBranch<float>("ak12_reclustered_wo_lepton_softdropMass");
    ana::output_ttreex.createBranch<float>("ak15_reclustered_wo_lepton_softdropMass");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_nopuppi_softdropMass");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_ca_softdropMass");

    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_nearest_dr");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_nearest_pt");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_mass_w_nearest");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_softdropMass_w_nearest");

    ana::output_ttreex.createBranch<float>("ak8_miniaod_softdropSubjetDR");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_w_lepton_softdropSubjetDR");
    ana::output_ttreex.createBranch<float>("ak8_reclustered_wo_lepton_softdropSubjetDR");

    ana::output_ttreex.createBranch<float>("mQQ");
    ana::output_ttreex.createBranch<float>("dr_L_QQ");

    ana::output_ttreex.createBranch<float>("J_nJettinessTau1");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau2");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau3");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau31");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau32");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau21");

    ana::output_ttreex.createBranch<float>("ak8_recl_nJettinessTau1");
    ana::output_ttreex.createBranch<float>("ak8_recl_nJettinessTau2");
    ana::output_ttreex.createBranch<float>("ak8_recl_nJettinessTau3");
    ana::output_ttreex.createBranch<float>("ak8_recl_nJettinessTau31");
    ana::output_ttreex.createBranch<float>("ak8_recl_nJettinessTau32");
    ana::output_ttreex.createBranch<float>("ak8_recl_nJettinessTau21");

    ana::output_ttreex.createBranch<float>("ak8_recl_wo_lepton_nJettinessTau1");
    ana::output_ttreex.createBranch<float>("ak8_recl_wo_lepton_nJettinessTau2");
    ana::output_ttreex.createBranch<float>("ak8_recl_wo_lepton_nJettinessTau3");
    ana::output_ttreex.createBranch<float>("ak8_recl_wo_lepton_nJettinessTau31");
    ana::output_ttreex.createBranch<float>("ak8_recl_wo_lepton_nJettinessTau32");
    ana::output_ttreex.createBranch<float>("ak8_recl_wo_lepton_nJettinessTau21");

}

//_____________________________________________________________________________
void util::add_slim_ttreex_outputs()
{
    // Reclustered jets
    ana::output_ttreex.createBranch<LV>("W_p4");
    ana::output_ttreex.createBranch<LV>("W_SD_p4");
    ana::output_ttreex.createBranch<float>("mW_SD");
    ana::output_ttreex.createBranch<float>("W_nJettinessTau21");
    ana::output_ttreex.createBranch<float>("W_nJettinessTau31");
    ana::output_ttreex.createBranch<float>("W_nJettinessTau32");
    ana::output_ttreex.createBranch<float>("W_nJettinessTau1");
    ana::output_ttreex.createBranch<float>("W_nJettinessTau2");
    ana::output_ttreex.createBranch<float>("W_nJettinessTau3");


    // Object kinematics
    ana::output_ttreex.createBranch<float>("ak8_pt0");
    ana::output_ttreex.createBranch<float>("ak8_pt1");
    ana::output_ttreex.createBranch<float>("L_pt");
    ana::output_ttreex.createBranch<float>("L_eta");
    ana::output_ttreex.createBranch<float>("L_abseta");
    ana::output_ttreex.createBranch<float>("J_pt");
    ana::output_ttreex.createBranch<float>("J_eta");
    ana::output_ttreex.createBranch<float>("H_pt");
    ana::output_ttreex.createBranch<float>("H_eta");
    ana::output_ttreex.createBranch<float>("QQ_pt");
    ana::output_ttreex.createBranch<float>("QQ_eta");
    ana::output_ttreex.createBranch<float>("V_pt");
    ana::output_ttreex.createBranch<float>("V_eta");
    ana::output_ttreex.createBranch<float>("R_pt");
    ana::output_ttreex.createBranch<float>("R_eta");
    ana::output_ttreex.createBranch<float>("Lmet_pt");

    // Lepton property
    ana::output_ttreex.createBranch<float>("L_sip3d");
    ana::output_ttreex.createBranch<float>("L_absip3d");
    ana::output_ttreex.createBranch<float>("L_absdxy");
    ana::output_ttreex.createBranch<float>("L_absdz");

    // Fat-jet property
    ana::output_ttreex.createBranch<float>("J_nJettinessTau21");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau31");
    ana::output_ttreex.createBranch<float>("J_nJettinessTau32");

    // Masses
    ana::output_ttreex.createBranch<float>("mQQ");
    ana::output_ttreex.createBranch<float>("mV");
    ana::output_ttreex.createBranch<float>("mJ");
    ana::output_ttreex.createBranch<float>("RecoH_max");
    ana::output_ttreex.createBranch<float>("RecoH_min");
    ana::output_ttreex.createBranch<float>("mDmax");
    ana::output_ttreex.createBranch<float>("mDmin");
    ana::output_ttreex.createBranch<float>("mLsubjet_max");
    ana::output_ttreex.createBranch<float>("mLsubjet_min");

    // Correlations
    ana::output_ttreex.createBranch<float>("deltaFrac");
    ana::output_ttreex.createBranch<float>("deltaFracv2");
    ana::output_ttreex.createBranch<float>("mLW");
    ana::output_ttreex.createBranch<float>("mRatio");
    ana::output_ttreex.createBranch<float>("mRatio_SD");
    ana::output_ttreex.createBranch<float>("dphiRJ");

    ana::output_ttreex.createBranch<float>("dphiLsubjet_max");
    ana::output_ttreex.createBranch<float>("dphiLsubjet_min");
    ana::output_ttreex.createBranch<float>("detaLsubjet_max");
    ana::output_ttreex.createBranch<float>("detaLsubjet_min");
    ana::output_ttreex.createBranch<float>("drLsubjet_max");
    ana::output_ttreex.createBranch<float>("drLsubjet_min");

    ana::output_ttreex.createBranch<float>("LSF1");
    ana::output_ttreex.createBranch<float>("LSF2");
    ana::output_ttreex.createBranch<float>("LSF_min");
    ana::output_ttreex.createBranch<float>("LSF_max");

}

//_____________________________________________________________________________
void util::add_ttreex_outputs()
{
    if (ana::make_slim_ttree)
        add_slim_ttreex_outputs();
    if (ana::study_reclustering)
        add_reclustering_study_ttreex_outputs();
}

//_____________________________________________________________________________
void util::make_slim_ttree()
{
    if (ana::cutflow.getCut("CutISR400MuMinus").pass)
    {

        // Do the jet reculstering the ClusterSequence is an object that holds the entire jet cluster information
        fastjet::ClusterSequence cs_wo_lep = cluster_jets(get_particles(true), 0.8);

        // Access the non-groomed reclustered jets
        std::vector<fastjet::PseudoJet> jets_wo_lep = fastjet::sorted_by_pt(cs_wo_lep.inclusive_jets());

        // Then, get_softdrop_jet function takes the leading jet and spits out the groomed jet (pseudojet object)
        fastjet::PseudoJet sd_jet_wo_lep = jets_wo_lep.size() > 0 ? get_softdrop_jet(jets_wo_lep[0]) : fastjet::PseudoJet();

        LV W_p4 = jets_wo_lep.size() > 0 ? getLV(jets_wo_lep[0]) : LV();
        LV W_SD_p4 = getLV(sd_jet_wo_lep);

        ana::output_ttreex.setBranch<LV>("W_p4", W_p4);
        ana::output_ttreex.setBranch<LV>("W_SD_p4", W_SD_p4);
        ana::output_ttreex.setBranch<float>("mW_SD", sd_jet_wo_lep.m());

        // Re-compute nTau to reproduce miniaod
        // https://github.com/cms-sw/cmssw/blob/CMSSW_8_0_3_patchX/RecoJets/JetProducers/python/nJettinessAdder_cfi.py
        // https://github.com/cms-sw/cmssw/blob/76f5d38567bfc85949371c5b46d2a597cd2b128e/RecoJets/JetProducers/plugins/NjettinessAdder.cc
        // https://github.com/cms-sw/cmssw/blob/76f5d38567bfc85949371c5b46d2a597cd2b128e/RecoJets/JetProducers/interface/NjettinessAdder.h
        fastjet::contrib::Nsubjettiness      nSub1_beta1(1, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::Nsubjettiness      nSub2_beta1(2, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::Nsubjettiness      nSub3_beta1(3, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::NsubjettinessRatio nSub31_beta1(3, 1, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::NsubjettinessRatio nSub32_beta1(3, 2, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::NsubjettinessRatio nSub21_beta1(2, 1, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        float nTau1_wo_lep  = jets_wo_lep.size() > 0 ? nSub1_beta1(jets_wo_lep[0]) : -999;
        float nTau2_wo_lep  = jets_wo_lep.size() > 0 ? nSub2_beta1(jets_wo_lep[0]) : -999;
        float nTau3_wo_lep  = jets_wo_lep.size() > 0 ? nSub3_beta1(jets_wo_lep[0]) : -999;
        float nTau31_wo_lep = jets_wo_lep.size() > 0 ? nSub31_beta1(jets_wo_lep[0]) : -999;
        float nTau32_wo_lep = jets_wo_lep.size() > 0 ? nSub32_beta1(jets_wo_lep[0]) : -999;
        float nTau21_wo_lep = jets_wo_lep.size() > 0 ? nSub21_beta1(jets_wo_lep[0]) : -999;

        // Set njettiness
        ana::output_ttreex.setBranch<float>("W_nJettinessTau1", nTau1_wo_lep);
        ana::output_ttreex.setBranch<float>("W_nJettinessTau2", nTau2_wo_lep);
        ana::output_ttreex.setBranch<float>("W_nJettinessTau3", nTau3_wo_lep);
        ana::output_ttreex.setBranch<float>("W_nJettinessTau31", nTau31_wo_lep);
        ana::output_ttreex.setBranch<float>("W_nJettinessTau32", nTau32_wo_lep);
        ana::output_ttreex.setBranch<float>("W_nJettinessTau21", nTau21_wo_lep);

        // Object kinematics
        ana::output_ttreex.setBranch<float>("ak8_pt0", hww.ak8jets_p4().size() > 0 ? hww.ak8jets_p4()[0].pt() : -999);
        ana::output_ttreex.setBranch<float>("ak8_pt1", hww.ak8jets_p4().size() > 1 ? hww.ak8jets_p4()[1].pt() : -999);
        ana::output_ttreex.setBranch<float>("L_pt", hww.L_p4().pt());
        ana::output_ttreex.setBranch<float>("L_eta", hww.L_p4().eta());
        ana::output_ttreex.setBranch<float>("L_abseta", fabs(hww.L_p4().eta()));
        ana::output_ttreex.setBranch<float>("J_pt", hww.J_p4().pt());
        ana::output_ttreex.setBranch<float>("J_eta", hww.J_p4().eta());
        ana::output_ttreex.setBranch<float>("H_pt", hww.H_p4().pt());
        ana::output_ttreex.setBranch<float>("H_eta", hww.H_p4().eta());
        ana::output_ttreex.setBranch<float>("QQ_pt", hww.QQ_p4().pt());
        ana::output_ttreex.setBranch<float>("QQ_eta", hww.QQ_p4().eta());
        ana::output_ttreex.setBranch<float>("V_pt", hww.V_p4().pt());
        ana::output_ttreex.setBranch<float>("V_eta", hww.V_p4().eta());
        ana::output_ttreex.setBranch<float>("R_pt", hww.Recoil_p4().pt());
        ana::output_ttreex.setBranch<float>("R_eta", hww.Recoil_p4().eta());
        ana::output_ttreex.setBranch<float>("Lmet_pt", hww.Lmet_p4().pt());

        // Lepton property
        ana::output_ttreex.setBranch<float>("L_sip3d", fabs(hww.L_ip3d() / hww.L_ip3derr()));
        ana::output_ttreex.setBranch<float>("L_absip3d", fabs(hww.L_ip3d()));
        ana::output_ttreex.setBranch<float>("L_absdxy", fabs(hww.L_dxy()));
        ana::output_ttreex.setBranch<float>("L_absdz", fabs(hww.L_dz()));

        // Fat-jet property
        ana::output_ttreex.setBranch<float>("J_nJettinessTau21", hww.J_nJettinessTau2() / hww.J_nJettinessTau1() );
        ana::output_ttreex.setBranch<float>("J_nJettinessTau31", hww.J_nJettinessTau3() / hww.J_nJettinessTau1() );
        ana::output_ttreex.setBranch<float>("J_nJettinessTau32", hww.J_nJettinessTau3() / hww.J_nJettinessTau2() );

        // Masses
        ana::output_ttreex.setBranch<float>("mQQ", hww.QQ_p4().mass());
        ana::output_ttreex.setBranch<float>("mV", hww.V_p4().mass());
        ana::output_ttreex.setBranch<float>("mJ", hww.J_p4().mass());
        float massh1 = (W_SD_p4 + hww.L_p4() + hww.neu_p4_sol1()).mass();
        float massh2 = (W_SD_p4 + hww.L_p4() + hww.neu_p4_sol2()).mass();
        ana::output_ttreex.setBranch<float>("RecoH_max", massh1 > massh2 ? massh1 : massh2);
        ana::output_ttreex.setBranch<float>("RecoH_min", massh1 > massh2 ? massh2 : massh1);

        // Mass variable from B2G-18-008
        LV Lv1 = hww.L_p4() + hww.neu_p4_sol1();
        LV Lv2 = hww.L_p4() + hww.neu_p4_sol2();
        // float DR1 = RooUtil::Calc::DeltaR(Lv1, hww.QQ_p4());
        // float DR2 = RooUtil::Calc::DeltaR(Lv2, hww.QQ_p4());
        // float Pt1 = (Lv1 + hww.QQ_p4()).pt();
        // float Pt2 = (Lv2 + hww.QQ_p4()).pt();
        float DR1 = RooUtil::Calc::DeltaR(Lv1, W_SD_p4);
        float DR2 = RooUtil::Calc::DeltaR(Lv2, W_SD_p4);
        float Pt1 = (Lv1 + W_SD_p4).pt();
        float Pt2 = (Lv2 + W_SD_p4).pt();
        float mD1 = DR1 * Pt1 / 2.;
        float mD2 = DR2 * Pt2 / 2.;
        ana::output_ttreex.setBranch<float>("mDmax", mD1 > mD2 ? mD1 : mD2);
        ana::output_ttreex.setBranch<float>("mDmin", mD1 > mD2 ? mD2 : mD1);

        // Correlations
        ana::output_ttreex.setBranch<float>("deltaFrac", hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt());
        ana::output_ttreex.setBranch<float>("deltaFracv2", hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - W_SD_p4.pt() / hww.Recoil_p4().pt());
        ana::output_ttreex.setBranch<float>("mLW", (hww.L_p4() + W_SD_p4).mass());
        ana::output_ttreex.setBranch<float>("mRatio", hww.V_p4().mass() / W_p4.mass());
        ana::output_ttreex.setBranch<float>("mRatio_SD", hww.V_softdropMass() / W_SD_p4.mass());
        ana::output_ttreex.setBranch<float>("dphiRJ", fabs(RooUtil::Calc::DeltaPhi(hww.Recoil_p4(), hww.J_p4())));

        // Correlations if the subjet exists
        if (sd_jet_wo_lep.has_pieces())
        {

            std::vector<fastjet::PseudoJet> sd_jet_wo_lep_pieces = fastjet::sorted_by_pt(sd_jet_wo_lep.pieces());

            LV subjet1 = getLV(sd_jet_wo_lep_pieces[0]);
            LV subjet2 = getLV(sd_jet_wo_lep_pieces[1]);
            float m1 = (hww.L_p4() + subjet1).mass();
            float m2 = (hww.L_p4() + subjet2).mass();
            float dphi1 = fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), subjet1));
            float dphi2 = fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), subjet2));
            float deta1 = fabs(RooUtil::Calc::DeltaEta(hww.L_p4(), subjet1));
            float deta2 = fabs(RooUtil::Calc::DeltaEta(hww.L_p4(), subjet2));
            float dr1 = fabs(RooUtil::Calc::DeltaR(hww.L_p4(), subjet1));
            float dr2 = fabs(RooUtil::Calc::DeltaR(hww.L_p4(), subjet2));
            float lsf1 = hww.L_p4().pt() / subjet1.pt();
            float lsf2 = hww.L_p4().pt() / subjet2.pt();

            ana::output_ttreex.setBranch<float>("mLsubjet_max", m1 > m2 ? m1 : m2);
            ana::output_ttreex.setBranch<float>("mLsubjet_min", m1 > m2 ? m2 : m1);
            ana::output_ttreex.setBranch<float>("dphiLsubjet_max", m1 > m2 ? dphi1 : dphi2);
            ana::output_ttreex.setBranch<float>("dphiLsubjet_min", m1 > m2 ? dphi2 : dphi1);
            ana::output_ttreex.setBranch<float>("detaLsubjet_max", m1 > m2 ? deta1 : deta2);
            ana::output_ttreex.setBranch<float>("detaLsubjet_min", m1 > m2 ? deta2 : deta1);
            ana::output_ttreex.setBranch<float>("drLsubjet_max", m1 > m2 ? dr1 : dr2);
            ana::output_ttreex.setBranch<float>("drLsubjet_min", m1 > m2 ? dr2 : dr1);

            ana::output_ttreex.setBranch<float>("LSF1", lsf1);
            ana::output_ttreex.setBranch<float>("LSF2", lsf2);
            ana::output_ttreex.setBranch<float>("LSF_max", m1 > m2 ? lsf1 : lsf2);
            ana::output_ttreex.setBranch<float>("LSF_min", m1 > m2 ? lsf2 : lsf1);

        }


        ana::output_ttreex.fill();

    }

}

//_____________________________________________________________________________
void util::run_study_reclustering()
{
    if (ana::cutflow.getCut("CutISR400MuMinus").pass)
    {

        // Do the jet reculstering the ClusterSequence is an object that holds the entire jet cluster information
        fastjet::ClusterSequence cs_w_lep          = cluster_jets(get_particles(false), 0.8);
        fastjet::ClusterSequence cs_wo_lep         = cluster_jets(get_particles(true, false, true), 0.8);
        fastjet::ClusterSequence cs_wo_lep_6       = cluster_jets(get_particles(true, false, true), 0.6);
        fastjet::ClusterSequence cs_wo_lep_12      = cluster_jets(get_particles(true), 1.2);
        fastjet::ClusterSequence cs_wo_lep_15      = cluster_jets(get_particles(true), 1.5);
        fastjet::ClusterSequence cs_wo_lep_nopuppi = cluster_jets(get_particles(true, true), 0.8);
        fastjet::ClusterSequence cs_wo_lep_ca      = cluster_jets(get_particles(true), 0.8, fastjet::cambridge_algorithm);

        // Access the non-groomed reclustered jets
        std::vector<fastjet::PseudoJet> jets_w_lep          = fastjet::sorted_by_pt(cs_w_lep.inclusive_jets());
        std::vector<fastjet::PseudoJet> jets_wo_lep         = fastjet::sorted_by_pt(cs_wo_lep.inclusive_jets());
        std::vector<fastjet::PseudoJet> jets_wo_lep_6       = fastjet::sorted_by_pt(cs_wo_lep_6.inclusive_jets());
        std::vector<fastjet::PseudoJet> jets_wo_lep_12      = fastjet::sorted_by_pt(cs_wo_lep_12.inclusive_jets());
        std::vector<fastjet::PseudoJet> jets_wo_lep_15      = fastjet::sorted_by_pt(cs_wo_lep_15.inclusive_jets());
        std::vector<fastjet::PseudoJet> jets_wo_lep_nopuppi = fastjet::sorted_by_pt(cs_wo_lep_nopuppi.inclusive_jets());
        std::vector<fastjet::PseudoJet> jets_wo_lep_ca      = fastjet::sorted_by_pt(cs_wo_lep_ca.inclusive_jets());

        // Then, get_softdrop_jet function takes the leading jet and spits out the groomed jet (pseudojet object)
        fastjet::PseudoJet sd_jet_w_lep          = jets_w_lep.size() > 0          ? get_softdrop_jet(jets_w_lep[0])          : fastjet::PseudoJet();
        fastjet::PseudoJet sd_jet_wo_lep         = jets_wo_lep.size() > 0         ? get_softdrop_jet(jets_wo_lep[0])         : fastjet::PseudoJet();
        fastjet::PseudoJet sd_jet_wo_lep_6       = jets_wo_lep_6.size() > 0       ? get_softdrop_jet(jets_wo_lep_6[0])       : fastjet::PseudoJet();
        fastjet::PseudoJet sd_jet_wo_lep_12      = jets_wo_lep_12.size() > 0      ? get_softdrop_jet(jets_wo_lep_12[0])      : fastjet::PseudoJet();
        fastjet::PseudoJet sd_jet_wo_lep_15      = jets_wo_lep_15.size() > 0      ? get_softdrop_jet(jets_wo_lep_15[0])      : fastjet::PseudoJet();
        fastjet::PseudoJet sd_jet_wo_lep_nopuppi = jets_wo_lep_nopuppi.size() > 0 ? get_softdrop_jet(jets_wo_lep_nopuppi[0]) : fastjet::PseudoJet();
        fastjet::PseudoJet sd_jet_wo_lep_ca      = jets_wo_lep_ca.size() > 0      ? get_softdrop_jet(jets_wo_lep_ca[0])      : fastjet::PseudoJet();

        // The leading one will be my reclustered jet of interest
        float recl_w_lep_pt = jets_w_lep.size() > 0 ? jets_w_lep[0].pt() : -999;
        float recl_w_lep_eta = jets_w_lep.size() > 0 ? jets_w_lep[0].eta() : -999;
        float recl_w_lep_phi = jets_w_lep.size() > 0 ? jets_w_lep[0].phi() : -999;
        float recl_w_lep_mass = jets_w_lep.size() > 0 ? jets_w_lep[0].m() : -999;

        // Just accessing mini AOD jet
        LV raw_J = hww.J_p4() * hww.J_undoJEC();
        float miniaod_pt = raw_J.pt();
        float miniaod_eta = raw_J.eta();
        float miniaod_phi = raw_J.phi();
        float miniaod_mass = raw_J.mass();

        // // Accessing the sub-raw_J
        // std::vector<fastjet::PseudoJet> sd_jet_w_lep_pieces = fastjet::sorted_by_pt(sd_jet_w_lep.pieces());
        // std::vector<fastjet::PseudoJet> sd_jet_wo_lep_pieces = fastjet::sorted_by_pt(sd_jet_wo_lep.pieces());

        ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_dpt_wrt_miniaod", miniaod_pt - recl_w_lep_pt);
        ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_deta_wrt_miniaod", miniaod_eta - recl_w_lep_eta);
        ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_dphi_wrt_miniaod", miniaod_phi - recl_w_lep_phi);
        ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_dmass_wrt_miniaod", miniaod_mass - recl_w_lep_mass);

        if (jets_w_lep.size() > 0) ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_mass", jets_w_lep[0].m());
        if (jets_wo_lep.size() > 0) ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_mass", jets_wo_lep[0].m());
        if (jets_wo_lep_6.size() > 0) ana::output_ttreex.setBranch<float>("ak12_reclustered_wo_lepton_mass", jets_wo_lep_6[0].m());
        if (jets_wo_lep_12.size() > 0) ana::output_ttreex.setBranch<float>("ak12_reclustered_wo_lepton_mass", jets_wo_lep_12[0].m());
        if (jets_wo_lep_15.size() > 0) ana::output_ttreex.setBranch<float>("ak15_reclustered_wo_lepton_mass", jets_wo_lep_15[0].m());
        if (jets_wo_lep_nopuppi.size() > 0) ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_nopuppi_mass", jets_wo_lep_nopuppi[0].m());
        if (jets_wo_lep_ca.size() > 0) ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_ca_mass", jets_wo_lep_ca[0].m());

        ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_softdropMass", sd_jet_w_lep.m());
        ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_softdropMass", sd_jet_wo_lep.m());
        ana::output_ttreex.setBranch<float>("ak6_reclustered_wo_lepton_softdropMass", sd_jet_wo_lep_6.m());
        ana::output_ttreex.setBranch<float>("ak12_reclustered_wo_lepton_softdropMass", sd_jet_wo_lep_12.m());
        ana::output_ttreex.setBranch<float>("ak15_reclustered_wo_lepton_softdropMass", sd_jet_wo_lep_15.m());
        ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_nopuppi_softdropMass", sd_jet_wo_lep_nopuppi.m());
        ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_ca_softdropMass", sd_jet_wo_lep_ca.m());

        // If I have more than 1 clustered AK8 jets, then loop over to find the leading one in the Rmod < 2*R (1.6)
        if (jets_wo_lep.size() > 1)
        {
            // Finding the closest jet by looping over and computing deltaR and comparing
            unsigned int i_nearest = -1;
            float dr = -999;
            float mass = -999;
            float pt = -999;
            for (unsigned int ii = 1; ii < jets_wo_lep.size(); ++ii)
            {
                // float tmp = jets_wo_lep[0].delta_R(jets_wo_lep[ii]);
                float tmp = jets_wo_lep[ii].pt();
                if (tmp > pt)
                {
                    i_nearest = ii;
                    dr = jets_wo_lep[0].delta_R(jets_wo_lep[ii]);
                    pt = jets_wo_lep[ii].pt();
                    mass = (getLV(jets_wo_lep[0]) + getLV(jets_wo_lep[ii])).mass();
                }
            }
            if (i_nearest > 0)
            {
                ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_nearest_dr", dr);
                ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_nearest_pt", pt);
                ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_mass_w_nearest", mass);

                // Computing softdrop after adding the nearest jet
                fastjet::PseudoJet combined_jet = jets_wo_lep[0];
                combined_jet += jets_wo_lep[i_nearest];

                double z_cut = 0.10;
                double beta  = 0.0;
                fastjet::contrib::SoftDrop sd(beta, z_cut);

                // Run SoftDrop and examine the output
                fastjet::PseudoJet sd_jet = sd(combined_jet);

                ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_softdropMass_w_nearest", sd_jet.m());
            }

        }

        if (jets_w_lep.size() > 0)
            ana::output_ttreex.setBranch<float>("ak8_reclustered_w_lepton_softdropSubjetDR", sd_jet_w_lep.structure_of<fastjet::contrib::SoftDrop>().delta_R());
        if (jets_wo_lep.size() > 0)
            ana::output_ttreex.setBranch<float>("ak8_reclustered_wo_lepton_softdropSubjetDR", sd_jet_wo_lep.structure_of<fastjet::contrib::SoftDrop>().delta_R());

        ana::output_ttreex.setBranch<float>("ak8_miniaod_mass", hww.J_p4().mass());
        ana::output_ttreex.setBranch<float>("ak8_miniaod_softdropMass", hww.J_softdropMass());
        ana::output_ttreex.setBranch<float>("ak8_miniaod_softdropSubjetDR",
                RooUtil::Calc::DeltaR(
                    RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet1_pt(),hww.J_softdropPuppiSubjet1_eta(),hww.J_softdropPuppiSubjet1_phi(),hww.J_softdropPuppiSubjet1_mass()),
                    RooUtil::Calc::getLV(hww.J_softdropPuppiSubjet2_pt(),hww.J_softdropPuppiSubjet2_eta(),hww.J_softdropPuppiSubjet2_phi(),hww.J_softdropPuppiSubjet2_mass())
                    )
                );

        // Compute gen level related quantities
        if (ana::input_file_list_tstring.Contains("M125"))
        {
            ana::output_ttreex.setBranch<float>("gen_q0_pt", hww.gen_q0_p4().pt());
            ana::output_ttreex.setBranch<float>("gen_q1_pt", hww.gen_q1_p4().pt());
            ana::output_ttreex.setBranch<float>("gen_dr_qq", RooUtil::Calc::DeltaR(hww.gen_q0_p4(), hww.gen_q1_p4()));
            ana::output_ttreex.setBranch<float>("gen_mass_qq", (hww.gen_q0_p4() + hww.gen_q1_p4()).mass());
            ana::output_ttreex.setBranch<float>("gen_mass_lqq", (hww.gen_q0_p4() + hww.gen_q1_p4() + hww.gen_lep_p4()).mass());
            ana::output_ttreex.setBranch<float>("gen_whad_pt", hww.gen_whad_p4().pt());
            ana::output_ttreex.setBranch<float>("gen_wlep_pt", hww.gen_wlep_p4().pt());
        }

        // Compute reco level related quantities
        ana::output_ttreex.setBranch<float>("deltaFrac", hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt());
        ana::output_ttreex.setBranch<float>("mQQ", hww.QQ_p4().mass());
        ana::output_ttreex.setBranch<float>("dr_L_QQ", hww.dr_L_QQ());

        // Save weights for plotting
        ana::output_ttreex.setBranch<float>("wgt", hww.evt_scale1fb() * 35.9);

        // Nsubjettiness variables
        ana::output_ttreex.setBranch<float>("J_nJettinessTau1"  , hww.J_nJettinessTau1()                          );
        ana::output_ttreex.setBranch<float>("J_nJettinessTau2"  , hww.J_nJettinessTau2()                          );
        ana::output_ttreex.setBranch<float>("J_nJettinessTau3"  , hww.J_nJettinessTau3()                          );
        ana::output_ttreex.setBranch<float>("J_nJettinessTau31" , hww.J_nJettinessTau3() / hww.J_nJettinessTau1() );
        ana::output_ttreex.setBranch<float>("J_nJettinessTau32" , hww.J_nJettinessTau3() / hww.J_nJettinessTau2() );
        ana::output_ttreex.setBranch<float>("J_nJettinessTau21" , hww.J_nJettinessTau2() / hww.J_nJettinessTau1() );

        // https://github.com/cms-sw/cmssw/blob/CMSSW_8_0_3_patchX/RecoJets/JetProducers/python/nJettinessAdder_cfi.py
        // https://github.com/cms-sw/cmssw/blob/76f5d38567bfc85949371c5b46d2a597cd2b128e/RecoJets/JetProducers/plugins/NjettinessAdder.cc
        // https://github.com/cms-sw/cmssw/blob/76f5d38567bfc85949371c5b46d2a597cd2b128e/RecoJets/JetProducers/interface/NjettinessAdder.h
        fastjet::contrib::Nsubjettiness      nSub1_beta1(1, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::Nsubjettiness      nSub2_beta1(2, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::Nsubjettiness      nSub3_beta1(3, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::NsubjettinessRatio nSub31_beta1(3, 1, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::NsubjettinessRatio nSub32_beta1(3, 2, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));
        fastjet::contrib::NsubjettinessRatio nSub21_beta1(2, 1, fastjet::contrib::OnePass_KT_Axes(), fastjet::contrib::NormalizedMeasure(1.0, 0.8));

        // Re-compute nTau to reproduce miniaod
        float nTau1_w_lep  = jets_w_lep.size() > 0 ? nSub1_beta1(jets_w_lep[0]) : -999;
        float nTau2_w_lep  = jets_w_lep.size() > 0 ? nSub2_beta1(jets_w_lep[0]) : -999;
        float nTau3_w_lep  = jets_w_lep.size() > 0 ? nSub3_beta1(jets_w_lep[0]) : -999;
        float nTau31_w_lep = jets_w_lep.size() > 0 ? nSub31_beta1(jets_w_lep[0]) : -999;
        float nTau32_w_lep = jets_w_lep.size() > 0 ? nSub32_beta1(jets_w_lep[0]) : -999;
        float nTau21_w_lep = jets_w_lep.size() > 0 ? nSub21_beta1(jets_w_lep[0]) : -999;

        // Re-compute nTau to reproduce miniaod
        float nTau1_wo_lep  = jets_wo_lep.size() > 0 ? nSub1_beta1(jets_wo_lep[0]) : -999;
        float nTau2_wo_lep  = jets_wo_lep.size() > 0 ? nSub2_beta1(jets_wo_lep[0]) : -999;
        float nTau3_wo_lep  = jets_wo_lep.size() > 0 ? nSub3_beta1(jets_wo_lep[0]) : -999;
        float nTau31_wo_lep = jets_wo_lep.size() > 0 ? nSub31_beta1(jets_wo_lep[0]) : -999;
        float nTau32_wo_lep = jets_wo_lep.size() > 0 ? nSub32_beta1(jets_wo_lep[0]) : -999;
        float nTau21_wo_lep = jets_wo_lep.size() > 0 ? nSub21_beta1(jets_wo_lep[0]) : -999;

        // Set njettiness
        ana::output_ttreex.setBranch<float>("ak8_recl_nJettinessTau1", nTau1_w_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_nJettinessTau2", nTau2_w_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_nJettinessTau3", nTau3_w_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_nJettinessTau31", nTau31_w_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_nJettinessTau32", nTau32_w_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_nJettinessTau21", nTau21_w_lep);

        // Set njettiness
        ana::output_ttreex.setBranch<float>("ak8_recl_wo_lepton_nJettinessTau1", nTau1_wo_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_wo_lepton_nJettinessTau2", nTau2_wo_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_wo_lepton_nJettinessTau3", nTau3_wo_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_wo_lepton_nJettinessTau31", nTau31_wo_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_wo_lepton_nJettinessTau32", nTau32_wo_lep);
        ana::output_ttreex.setBranch<float>("ak8_recl_wo_lepton_nJettinessTau21", nTau21_wo_lep);

        ana::output_ttreex.fill();
    }
}

//__________________________________________________________________________________________________
// Do clusterinng where the input: particles is a list of Pseudo jets (constituents such as PF or calo clusters etc.)
// Perofrom Anti-kt clustering on vector of PseudoJets (probably a PF candidate list)
fastjet::ClusterSequence util::cluster_jets(std::vector<fastjet::PseudoJet> particles, double R, fastjet::JetAlgorithm jetalgo)
{
    // choose a jet definition
    fastjet::JetDefinition jet_def(jetalgo, R);

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
std::vector<fastjet::PseudoJet> util::get_particles(bool subtract_lepton, bool do_not_subtract_puppi, bool log_subtracted_lepton)
{
    std::vector<fastjet::PseudoJet> particles;

    // Htag_pf_p4 contains the pf candidates around the fat-jet candidate
    // For a puppi jet reclustering, pf candidates are weighted by each weight

    for (unsigned int ipf = 0; ipf < hww.Htag_pf_p4().size(); ++ipf)
    {
        float puppi_wgt = hww.Htag_pf_puppi_wgt()[ipf];

        if (puppi_wgt == 0 and not do_not_subtract_puppi)
            continue;

        if (subtract_lepton)
        {
            float dr = RooUtil::Calc::DeltaR(hww.Htag_pf_p4()[ipf], hww.L_p4());
            if (dr < 0.1 and hww.Htag_pf_id()[ipf] == hww.L_id())
            {
                if (log_subtracted_lepton)
                {
                    ana::output_ttreex.setBranch<float>("ak8_lepton_subtraction_dpt", hww.Htag_pf_p4()[ipf].pt() - hww.L_p4().pt());
                    ana::output_ttreex.setBranch<float>("ak8_lepton_subtraction_dr", dr);
                    ana::output_ttreex.setBranch<float>("ak8_lepton_subtraction_id", hww.Htag_pf_id()[ipf]);
                }
                continue;
            }
        }
        LV pf = do_not_subtract_puppi ? hww.Htag_pf_p4()[ipf] : hww.Htag_pf_p4()[ipf] * puppi_wgt;

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
fastjet::PseudoJet util::get_softdrop_jet(fastjet::PseudoJet& jet)
{

    // give the soft drop groomer a short name
    // Use a symmetry cut z > z_cut R^beta
    // By default, there is no mass-drop requirement
    double z_cut = 0.10;
    double beta  = 0.0;
    fastjet::contrib::SoftDrop sd(beta, z_cut);

#ifdef DEBUG
    cout << "SoftDrop groomer is: " << sd.description() << endl;
#endif

    // Run SoftDrop and examine the output
    fastjet::PseudoJet sd_jet = sd(jet);

#ifdef DEBUG
    cout << endl;
    cout << "original    jet: " << jet << endl;
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

//__________________________________________________________________________________________________
LV getLV(fastjet::PseudoJet& jet)
{
    return RooUtil::Calc::getLV(jet.pt(), jet.eta(), jet.phi(), jet.m());
}
