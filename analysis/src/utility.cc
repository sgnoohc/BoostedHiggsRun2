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

}

//_____________________________________________________________________________
void util::create_histograms()
{
    //_____________________________________________________________________________
    // Histogram defintiions
    ana::histograms.addHistogram("L_pt"   , 180 , 0  , 600 , [&]() { return hww.L_p4().pt();   } );
    ana::histograms.addHistogram("L_eta"  , 180 , -3 , 3   , [&]() { return hww.L_p4().eta();  } );
    ana::histograms.addHistogram("J_pt"   , 180 , 0  , 600 , [&]() { return hww.J_p4().pt();   } );
    ana::histograms.addHistogram("J_eta"  , 180 , -5 , 5   , [&]() { return hww.J_p4().eta();  } );
    ana::histograms.addHistogram("H_pt"   , 180 , 0  , 600 , [&]() { return hww.H_p4().pt();   } );
    ana::histograms.addHistogram("H_eta"  , 180 , -5 , 5   , [&]() { return hww.H_p4().eta();  } );
    ana::histograms.addHistogram("QQ_pt"  , 180 , 0  , 600 , [&]() { return hww.QQ_p4().pt();  } );
    ana::histograms.addHistogram("QQ_eta" , 180 , -5 , 5   , [&]() { return hww.QQ_p4().eta(); } );
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
