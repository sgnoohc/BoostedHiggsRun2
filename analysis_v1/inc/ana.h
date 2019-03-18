#ifndef global_h
#define global_h

// ROOT
#include "TChain.h"
#include "TString.h"
#include "TFile.h"
#include "TTree.h"

// analysis
#include "rooutil.h"
#include "hwwtree.h"

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
    extern    RooUtil::TTreeX output_ttreex;

    // Looper
    extern    RooUtil::Looper<hwwtree> looper;

    // Cutflow utility object. This object is responsible for creating various
    // tree-like cutflow structure and booking cutflows/histograms to each cut
    // nodes.
    extern    RooUtil::Cutflow cutflow;

    // Histogram utility object that is used to define the histograms
    extern    RooUtil::Histograms histograms;

    // Boolean to control whehter or not to run the histograms
    extern    bool do_histograms;

    // Boolean to control whehter or not to book cutflow histogram (this can
    // actually be the bottle neck in speed)
    extern    bool do_cutflow;

    // Make slim TTree for a lightweight study
    extern    bool make_slim_ttree;

    // Make the study of reclustering jets
    extern    bool study_reclustering;

}

#endif
