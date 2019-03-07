#ifndef global_h
#define global_h

// ROOT
#include "TChain.h"
#include "TString.h"
#include "TFile.h"
#include "TTree.h"

// analysis
#include "rooutil.h"

namespace ana {

    // Comma separated list of input files. first argument
    extern    TString input_file_list_tstring;

    // Output TFile of the looper
    extern    TFile* output_tfile;

    // Total number of events to loop over
    extern    int n_events;

    // Main TChain that loops over your input
    extern    TChain* main_tchain;

    // A TTree object in case one wants to write out TTree from the looper
    extern    TTree* output_ttree;

    // A TTreeX object to handle output_ttree
    extern    RooUtil::TTreeX* output_ttreex;

}

#endif
