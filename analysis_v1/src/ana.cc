#include "ana.h"

namespace ana {

    // Comma separated list of input files. first argument
    TString input_file_list_tstring;

    // Output TFile of the looper
    TFile* output_tfile;

    // Total number of events to loop over
    int n_events;

    // Main TChain that loops over your input
    TChain* main_tchain;

    // A TTree object in case one wants to write out TTree from the looper
    TTree* output_ttree;

    // A TTreeX object to handle output_ttree
    RooUtil::TTreeX output_ttreex;

    // Looper
    RooUtil::Looper<hwwtree> looper;

    // Cutflow utility object. This object is responsible for creating various
    // tree-like cutflow structure and booking cutflows/histograms to each cut
    // nodes.
    RooUtil::Cutflow cutflow;

    // Histogram utility object that is used to define the histograms
    RooUtil::Histograms histograms;

    // Boolean to control whehter or not to run the histograms
    bool do_histograms;

    // Boolean to control whehter or not to book cutflow histogram (this can
    // actually be the bottle neck in speed)
    bool do_cutflow;

    // Make slim TTree for a lightweight study
    bool make_slim_ttree;;

    // Make the study of reclustering jets
    bool study_reclustering;


}

