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


}

