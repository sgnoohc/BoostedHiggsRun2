#include "hwwtree.h"
#include "rooutil.h"
#include "cxxopts.h"

namespace ana
{

    // Nevents to process
    int n_events;

    // Input file list stored as a comma separated strings
    TString input_file_list_tstring;

    // Output TFile that will hold histograms and cutflow histograms
    TFile* output_tfile;

    // Boolean flag to whether or not book the histograms
    bool do_histograms;

    // Boolean flag to whether or not book the cutflow histograms
    bool do_cutflow;

    // The TChain that holds the input TTree's
    TChain* events_tchain;

    // The RooUtil::Looper class takes in a list of TChain and loops them over
    // The code can be simpliifed to while (looper.nextEvent()) instead of using a for-based loop
    RooUtil::Looper<hwwtree> looper;

    // The RooUtil::Cutflow class helps user create complex cuttree structure
    // and book appropriate histograms at each cut stage
    RooUtil::Cutflow cutflow;

    // The RooUtil::Histogram class holds the definitions of histograms
    RooUtil::Histograms histograms;

}

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

    //********************************************************************************
    //
    // Parsing options
    //
    //********************************************************************************


    // Grand option setting
    cxxopts::Options options("\n  $ doAnalysis",  "\n********************************\n*                              *\n* Run 2 Boosted Higgs Analysis *\n*                              *\n********************************\n");

    options.add_options()
        ("i,input", "Comma separated input file list", cxxopts::value<std::string>())
        ("o,output", "Output file name", cxxopts::value<std::string>())
        ("n,nevents", "N events to loop over", cxxopts::value<int>()->default_value("-1"))
        ("t,test", "Run test job. i.e. overrides output option to 'test.root' and 'recreate's the file.")
        ("H,hist", "Book histogram")
        ("C,cutflow", "Book cutflows")
        ("h,help", "Print help")
        ;

    auto result = options.parse(argc, argv);

    //_______________________________________________________________________________
    // --help
    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    //_______________________________________________________________________________
    // --input
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

    //_______________________________________________________________________________
    // --nevents
    ana::n_events = result["nevents"].as<int>();

    //_______________________________________________________________________________
    // --test
    if (result.count("test"))
    {
        ana::output_tfile = new TFile("test.root", "recreate");
    }
    else
    {
        //_______________________________________________________________________________
        // --output
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

    //_______________________________________________________________________________
    // --hist
    if (result.count("hist"))
    {
        ana::do_histograms = true;
    }
    else
    {
        ana::do_histograms = false;
    }

    //_______________________________________________________________________________
    // --cutflow
    if (result.count("cutflow"))
    {
        ana::do_cutflow = true;
    }
    else
    {
        ana::do_cutflow = false;
    }

    // Printing out the option settings overview
    std::cout <<  "=========================================================" << std::endl;
    std::cout <<  " Setting of the analysis job based on provided arguments " << std::endl;
    std::cout <<  "---------------------------------------------------------" << std::endl;
    std::cout <<  " ana::input_file_list_tstring: " << ana::input_file_list_tstring <<  std::endl;
    std::cout <<  " ana::output_tfile: " << ana::output_tfile->GetName() <<  std::endl;
    std::cout <<  " ana::n_events: " << ana::n_events <<  std::endl;
    std::cout <<  " ana::do_cutflow: " << ana::do_cutflow <<  std::endl;
    std::cout <<  " ana::do_histograms: " << ana::do_histograms <<  std::endl;
    std::cout <<  "=========================================================" << std::endl;


    //********************************************************************************
    //
    // Opening input baby files
    //
    //********************************************************************************

    // Create the TChain that holds the TTree's of the baby ntuples
    ana::events_tchain = RooUtil::FileUtil::createTChain("t", ana::input_file_list_tstring);

    // Create a Looper object to loop over input files
    ana::looper.init(ana::events_tchain, &hww, ana::n_events);

    //********************************************************************************
    //
    // Creating the analysis using RooUtil::Cutflow class
    //
    //********************************************************************************

    // Set the cutflow object output file
    ana::cutflow.setTFile(ana::output_tfile);

    //________________________________________________________________________________
    // Define cuts
    ana::cutflow.addCut("CutWeight", [&]() { if (ana::input_file_list_tstring.Contains("w_incl")) return hww.gen_ht() < 400.; else return true; }, [&]() { if (ana::input_file_list_tstring.Contains("tt")) return hww.evt_scale1fb() * 35.9 * 0.011032 / 5.4366598; else return hww.evt_scale1fb() * 35.9; });
    ana::cutflow.addCutToLastActiveCut("CutNLep" , [&]() { return hww.L_p4().pt() > 0 and fabs(hww.L_dxy()) < 0.01 and fabs(hww.L_id()) == 13; } , UNITY );
    ana::cutflow.addCutToLastActiveCut("CutHad" , [&]() { return hww.LHRatio() < 0; } , UNITY );
    ana::cutflow.addCutToLastActiveCut("CutBVeto" , [&]() { return hww.nbmed() == 0; } , UNITY );
    ana::cutflow.addCutToLastActiveCut("CutHiggsPt", [&]() { return hww.LXJ_pt() > 400.; }, UNITY );
    ana::cutflow.addCutToLastActiveCut("CutDRLJ", [&]() { return hww.LJ_dr() < 0.8; }, UNITY );
    ana::cutflow.addCutToLastActiveCut("CutMiniIso", [&]() { return hww.L_miniIsoEA() < 0.05; }, UNITY );
    ana::cutflow.addCutToLastActiveCut("CutRelIso", [&]() { return hww.L_relIso04DB() > 0.2; }, UNITY );
    ana::cutflow.addCutToLastActiveCut("CutJmass", [&]() { return hww.J_SD_mass() > 20.; }, UNITY );
    ana::cutflow.addCutToLastActiveCut("CutJmassWindow", [&]() { return hww.J_SD_mass() > 60. and hww.J_SD_mass() < 95.; }, UNITY );

    //________________________________________________________________________________
    // Define histograms
    ana::histograms.addHistogram("LXJ_pt" , 180 , 0 , 600 , [&]() { return hww.LXJ_pt(); } );
    ana::histograms.addHistogram("L_miniIso" , 180 , 0 , 0.2 , [&]() { return hww.L_miniIsoEA(); } );
    ana::histograms.addHistogram("L_relIso04DB" , 180 , 0 , 1. , [&]() { return hww.L_relIso04DB(); } );
    ana::histograms.addHistogram("LJ_dr" , 180 , 0 , 3. , [&]() { return hww.LJ_dr(); } );
    ana::histograms.addHistogram("Lqmax_mass" , 180 , 0 , 200. , [&]() { return hww.Lqmax_mass(); } );
    ana::histograms.addHistogram("nj" , 10 , 0 , 10. , [&]() { return hww.nj(); } );
    ana::histograms.addHistogram("nj_in" , 10 , 0 , 10. , [&]() { return hww.nj_in(); } );
    ana::histograms.addHistogram("nj_annuli" , 10 , 0 , 10. , [&]() { return hww.nj_annuli(); } );
    ana::histograms.addHistogram("nj_same" , 10 , 0 , 10. , [&]() { return hww.nj_same(); } );
    ana::histograms.addHistogram("nj_away" , 10 , 0 , 10. , [&]() { return hww.nj_away(); } );
    ana::histograms.addHistogram("nb" , 5 , 0 , 5. , [&]() { return hww.nb(); } );
    ana::histograms.addHistogram("nb_in" , 5 , 0 , 5. , [&]() { return hww.nb_in(); } );
    ana::histograms.addHistogram("nb_annuli" , 5 , 0 , 5. , [&]() { return hww.nb_annuli(); } );
    ana::histograms.addHistogram("nb_same" , 5 , 0 , 5. , [&]() { return hww.nb_same(); } );
    ana::histograms.addHistogram("nb_away" , 5 , 0 , 5. , [&]() { return hww.nb_away(); } );
    ana::histograms.addHistogram("nbmed" , 5 , 0 , 5. , [&]() { return hww.nbmed(); } );
    ana::histograms.addHistogram("nbmed_in" , 5 , 0 , 5. , [&]() { return hww.nbmed_in(); } );
    ana::histograms.addHistogram("nbmed_annuli" , 5 , 0 , 5. , [&]() { return hww.nbmed_annuli(); } );
    ana::histograms.addHistogram("nbmed_same" , 5 , 0 , 5. , [&]() { return hww.nbmed_same(); } );
    ana::histograms.addHistogram("nbmed_away" , 5 , 0 , 5. , [&]() { return hww.nbmed_away(); } );
    ana::histograms.addHistogram("mD" , 180 , 0 , 300. , [&]() { return hww.mD(); } );
    ana::histograms.addHistogram("mD_Wlep" , 180 , 0 , 300. , [&]() { return hww.mD_Wlep(); } );
    ana::histograms.addHistogram("mH" , 180 , 0 , 300. , [&]() { return hww.mH(); } );
    ana::histograms.addHistogram("detW" , 180 , -300 , 300. , [&]() { return ((hww.detW() > 0) - (hww.detW() < 0)) * TMath::Sqrt(fabs(hww.detW())) / (2. * (hww.L_pt() * hww.L_pt() + hww.L_p4().mass() * hww.L_p4().mass())); } );
    ana::histograms.addHistogram("det" , 180 , -300 , 300. , [&]() { return ((hww.det() > 0) - (hww.det() < 0)) * TMath::Sqrt(fabs(hww.det())) / (2. * (hww.LJ_pt() * hww.LJ_pt() + hww.LJ_mass() * hww.LJ_mass())); } );
    ana::histograms.addHistogram("J_SD_mass" , 180 , 0 , 200. , [&]() { return hww.J_SD_mass(); } );
    ana::histograms.addHistogram("J_tau21" , 180 , 0 , 1. , [&]() { return hww.J_tau21(); } );
    ana::histograms.addHistogram("J_tau31" , 180 , 0 , 1. , [&]() { return hww.J_tau31(); } );
    ana::histograms.addHistogram("J_SD_tau21" , 180 , 0 , 1. , [&]() { return hww.J_SD_tau21(); } );
    ana::histograms.addHistogram("J_SD_tau31" , 180 , 0 , 1. , [&]() { return hww.J_SD_tau31(); } );
    ana::histograms.addHistogram("q0_pt" , 180 , 0 , 150. , [&]() { return hww.q0_pt(); } );
    ana::histograms.addHistogram("q1_pt" , 180 , 0 , 150. , [&]() { return hww.q1_pt(); } );
    ana::histograms.addHistogram("ht" , 180 , 0 , 600. , [&]() { return hww.ht(); } );
    ana::histograms.addHistogram("ht_in" , 180 , 0 , 600. , [&]() { return hww.ht_in(); } );
    ana::histograms.addHistogram("ht_annuli" , 180 , 0 , 600. , [&]() { return hww.ht_annuli(); } );
    ana::histograms.addHistogram("ht_same" , 180 , 0 , 600. , [&]() { return hww.ht_same(); } );
    ana::histograms.addHistogram("ht_away" , 180 , 0 , 600. , [&]() { return hww.ht_away(); } );

    ana::histograms.addHistogram("gen_b0_dr" , 180 , 0 , 5. , [&]() { return hww.gen_b0_dr(); } );
    ana::histograms.addHistogram("gen_b1_dr" , 180 , 0 , 5. , [&]() { return hww.gen_b1_dr(); } );
    ana::histograms.addHistogram("gen_t0_dr" , 180 , 0 , 5. , [&]() { return hww.gen_t0_dr(); } );
    ana::histograms.addHistogram("gen_t1_dr" , 180 , 0 , 5. , [&]() { return hww.gen_t1_dr(); } );

    ana::histograms.addVecHistogram("j_dphis" , 180 , 0 , 3.1416 , [&]() { std::vector<float> rtn; for (auto& phi : hww.j_dphis()) rtn.push_back(fabs(phi)); return rtn; } );
    ana::histograms.addVecHistogram("j_drs" , 180 , 0 , 6. , [&]() { return hww.j_drs(); } );

    // Book cutflows
    ana::cutflow.bookCutflows();

    // Book histograms
    ana::cutflow.bookHistograms(ana::histograms);

    // Print cut structure before starting the loop just to visually see it
    ana::cutflow.printCuts();

    // Looping input file
    while (ana::looper.nextEvent()) { ana::cutflow.fill(); }

    // Writing output file
    ana::cutflow.saveOutput();

    return 0;

}

////_____________________________________________________________________________
//// Some nested loops to create various cut regions with shorter lines of code
//// std::vector<TString> ISRbins = {"200", "200to300", "300", "300to400", "400", "400to450", "450", "450to500", "500", "500to600", "600"};
//// std::vector<TString> ISRbins = {"200", "300", "400", "450", "500", "600"};
//// std::vector<TString> ISRbins = {"300", "400", "500", "600"};
//std::vector<TString> ISRbins = {"400"};
//std::vector<TString> LeptonChannels = {"El", "Mu"};
//std::vector<TString> Charges = {"Plus", "Minus"};

//for (auto& ISRbin : ISRbins)
//{
//    std::vector<TString> ISRbinsLiteral;
//    // If the ISRbin literal expression contains "to" (e.g. 400to450) then define upper and lower cut
//    if (ISRbin.Contains("to"))
//    {
//        ISRbinsLiteral = RooUtil::StringUtil::split(ISRbin, "to");
//    }
//    // Otherwise go from lower cut to very large number cut
//    else
//    {
//        ISRbinsLiteral.push_back(ISRbin);
//        ISRbinsLiteral.push_back("999999999");
//    }
//    float lowISRbin  = ISRbinsLiteral[0].Atof(); // lower cut
//    float highISRbin = ISRbinsLiteral[1].Atof(); // upper cut
//    ana::cutflow.getCut("CutNAK8");
//    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin, [=]() { return hww.Recoil_p4().pt() > lowISRbin and hww.Recoil_p4().pt() < highISRbin; }, UNITY);
//    for (auto& lepton : LeptonChannels)
//    {
//        ana::cutflow.getCut("CutISR"+ISRbin);
//        if (lepton.EqualTo("El"))
//            ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton, [&]() { return abs(hww.L_id())==11; }, UNITY);
//        else
//            ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton, [&]() { return abs(hww.L_id())==13; }, UNITY);
//        for (auto& charge : Charges)
//        {
//            ana::cutflow.getCut("CutISR"+ISRbin+lepton);

//            if (lepton.EqualTo("El"))
//            {
//                if (charge.EqualTo("Plus"))
//                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge, [&]() { return hww.L_id()==-11;}, UNITY );
//                else
//                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge, [&]() { return hww.L_id()== 11;}, UNITY );
//            }
//            else if (lepton.EqualTo("Mu"))
//            {
//                if (charge.EqualTo("Plus"))
//                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge, [&]() { return hww.L_id()==-13;}, UNITY );
//                else
//                    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge, [&]() { return hww.L_id()== 13;}, UNITY );
//            }

//            ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge);
//            ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"GenHad", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() : 1; }, UNITY);
//            ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge);
//            ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"GenLep", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() : 1; }, UNITY);

//            ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge);
//            ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had", [&]()
//                    {
//                        return (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() < 0)
//                                and
//                                (
//                                 hww.HLT_Mu50()                                    || 
//                                 hww.HLT_TkMu50()                                  || 
//                                 hww.HLT_IsoMu24()                                 || 
//                                 hww.HLT_IsoTkMu24()                               || 
//                                 hww.HLT_AK8PFHT700_TrimR0p1PT0p03Mass50()         || 
//                                 hww.HLT_AK8PFJet360_TrimMass30()                  || 
//                                 hww.HLT_PFHT800()                                 || 
//                                 hww.HLT_PFHT900()                                 || 
//                                 hww.HLT_PFHT650_WideJetMJJ900DEtaJJ1p5()          || 
//                                 hww.HLT_PFHT650_WideJetMJJ950DEtaJJ1p5()          || 
//                                 hww.HLT_AK8PFDiJet280_200_TrimMass30_CSVM_0p20())
//                                ;
//                    }, UNITY);
//            {
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenHad", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() : 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenLep", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() : 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenHadOff", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() < 60.: 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenLepOff", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() < 60. : 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenHadOn", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() >= 60. : 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Had");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Had"+"GenLepOn", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() >= 60. : 1; }, UNITY);
//            }
//            ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge);
//            ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep", [&]()
//                    {
//                        return (hww.Lmet_p4().pt() / hww.Recoil_p4().pt() - hww.QQ_p4().pt() / hww.Recoil_p4().pt() > 0)
//                                and (hww.HLT_TkMu50() or hww.HLT_Mu50())
//                                and (hww.L_p4().pt() > 52.);
//                                ;
//                    }, UNITY);
//            {
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenHad", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() : 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenLep", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() : 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenHadOff", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() < 60.: 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenLepOff", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() < 60. : 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenHadOn", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() >= hww.gen_wlep_p4().pt() and hww.gen_whad_p4().mass() >= 60. : 1; }, UNITY);
//                ana::cutflow.getCut("CutISR"+ISRbin+lepton+charge+"Lep");
//                ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+lepton+charge+"Lep"+"GenLepOn", [&]() { return ana::input_file_list_tstring.Contains("M125") ? hww.gen_whad_p4().pt() <  hww.gen_wlep_p4().pt() and hww.gen_wlep_p4().mass() >= 60. : 1; }, UNITY);
//            }
//        }
//    }
//}

////_____________________________________________________________________________
//// Some strawman selections to each of the channel for study
//for (auto& ISRbin : ISRbins)
//{
//    // CutMuMinusHad
//    ana::cutflow.getCut("CutISR"+ISRbin+"MuMinusHad");
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut1", [&]() { return (hww.dr_L_QQ() < 0.8)                           ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return (hww.J_softdropMass() > 20.)                    ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)       ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut4", [&]() { return hww.QQ_p4().mass() > 65. and hww.QQ_p4().mass() < 100.; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut5", [&]() { return hww.L_customrelIso005EA() < 1.2                 ;}, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut6", [&]() { return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4()).mass() < 170;}, UNITY);

//    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadSubjetPt", [&]() { return hww.J_softdropPuppiSubjet1_pt() > 20 and hww.J_softdropPuppiSubjet2_pt() > 20.; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadNPFcands", [&]() { return hww.J_npfcands() < 65; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut1", [&]() { return hww.QQ_p4().mass() < 95. and hww.QQ_p4().mass() > 70.; }, UNITY);
//    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return ((hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() < (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass()) < 180; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut3", [&]() { return hww.J_softdropMass() > 80; }, UNITY);
//    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut4", [&]() { return hww.L_customrelIso005EA() < 1.12; }, UNITY);
//    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut5", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.); }, UNITY);
//    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut6", [&]() { return (hww.J_near_ak4jets_p4().size() > 0 ? fabs(RooUtil::Calc::DeltaPhi(hww.L_p4(), hww.J_near_ak4jets_p4()[0])) : -999) < 0.4; }, UNITY);

//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut1", [&]() { return hww.J_softdropMass() > 15. and hww.J_softdropMass() < 108; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut2", [&]() { return (hww.J_mass() < 130.)                    ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut3", [&]() { return hww.L_customrelIso005EA() < 1.12                 ;}, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut4", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 154.)       ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut5", [&]() { return ((hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() < (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass() ? (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol1()).mass() : (hww.QQ_p4() + hww.L_p4() + hww.neu_p4_sol2()).mass()) < 200.; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut6", [&]() { return hww.Recoil_p4().pt() / (hww.J_p4().pt() + hww.met_pt()) - 1; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusHadStrawManCut7", [&]() { return hww.QQ_p4().mass() > 70. and hww.QQ_p4().mass() < 100.; }, UNITY);

//    // CutMuPlusHad
//    ana::cutflow.getCut("CutISR"+ISRbin+"MuPlusHad");
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut1", [&]() { return (hww.dr_L_QQ() < 0.8)                            ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut2", [&]() { return (hww.J_softdropMass() > 20.)                     ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)        ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut4", [&]() { return hww.QQ_p4().mass() > 65. and hww.QQ_p4().mass() < 100.; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut5", [&]() { return hww.L_customrelIso005EA() < 1.2                  ;}, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusHadStrawManCut6", [&]() { return (hww.QQ_p4() + hww.L_p4() + hww.neu_p4()).mass() < 170;}, UNITY);

//    // CutMuMinusLep
//    ana::cutflow.getCut("CutISR"+ISRbin+"MuMinusLep");
//    ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut1", [&]() { return (hww.dr_L_QQ() > 0.12)                          ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut2", [&]() { return (hww.J_npfcands() > 15)                         ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)       ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut4", [&]() { return (hww.J_softdropMass() > 20)                     ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut5", [&]() { return (hww.J_deep_rawdisc_qcd() < 0.5)                ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut6", [&]() { return (hww.L_relIso03EA() > 0.2)                      ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut7", [&]() { return (hww.L_miniIsoEA() < 0.04)                      ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuMinusLepStrawManCut8", [&]() { return (hww.J_deep_rawdisc_w() > 0.1)                  ; }, UNITY);

//    // CutMuPlusLep
//    ana::cutflow.getCut("CutISR"+ISRbin+"MuPlusLep");
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut1", [&]() { return (hww.dr_L_QQ() > 0.12)                           ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut2", [&]() { return (hww.J_npfcands() > 15)                          ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut3", [&]() { return ((hww.L_p4() + hww.J_p4()).mass() < 150.)        ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut4", [&]() { return (hww.J_softdropMass() > 20)                      ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut5", [&]() { return (hww.J_deep_rawdisc_qcd() < 0.3)                 ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut6", [&]() { return (hww.L_relIso03EA() > 0.2)                       ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut7", [&]() { return (hww.L_miniIsoEA() < 0.04)                       ; }, UNITY);
//    // ana::cutflow.addCutToLastActiveCut("CutISR"+ISRbin+"MuPlusLepStrawManCut8", [&]() { return (hww.J_deep_rawdisc_w() > 0.1)                   ; }, UNITY);
//}

