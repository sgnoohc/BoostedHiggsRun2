#include "utility.h"

//_____________________________________________________________________________
std::tuple<TString, TFile*, int> util::parse_arguments(int argc, char** argv)
{

    // Argument checking
    if (argc < 3)
    {
        std::cout << "Usage:" << std::endl;
        std::cout << "  $ ./process INPUTFILES OUTPUTFILE [NEVENTS]" << std::endl;
        std::cout << std::endl;
        std::cout << "  INPUTFILES      comma separated file list" << std::endl;
        std::cout << "  OUTPUTFILE      output file" << std::endl;
        std::cout << "  [NEVENTS=-1]    # of events to run over" << std::endl;
        std::cout << std::endl;
        exit(1);
    }

    // Argument 1:
    // Comma separated input string
    ana::input_file_list_tstring = argv[1];

    // Argument 2:
    // Creating output file where we will put the outputs of the processing
    ana::output_tfile = new TFile(argv[2], "create");

    if (not ofile->IsOpen())
    {
        std::cout << "Error: output already exists! provide new output name or delete old file. OUTPUTFILE=" << argv[2] << std::endl;
        exit(1);
    }

    // Argument 3:
    // Number of events to loop over
    ana::n_events = argc > 3 ? atoi(argv[3]) : -1;

    return;

}

//_____________________________________________________________________________
void util::initialize_analysis()
{

    // TTreeX
    ana::output_ttreex = create_bdt_ttreex();

    return;

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
