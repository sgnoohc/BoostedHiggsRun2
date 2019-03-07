#ifndef utility_h
#define utility_h

// C
#include <tuple>
#include <stdlib.h>

// ROOT
#include "TString.h"
#include "TFile.h"

// analysis
#include "rooutil.h"
#include "ana.h"
#include "cxxopts.h"

namespace util
{
    // Parse input arguments
    void parse_arguments(int argc, char** argv);

    // Initialize analysis (any basic loading prior to looping will be placed here)
    void initialize_analysis();

    // Create a TTreeX object for the BDT (either for creating a training set or to evaluate)
    RooUtil::TTreeX create_bdt_ttreex();
}


#endif
