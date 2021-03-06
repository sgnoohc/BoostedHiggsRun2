#ifndef utility_h
#define utility_h

// C
#include <tuple>
#include <stdlib.h>
#include <iostream>
#include <ostream>

// ROOT
#include "TString.h"
#include "TFile.h"

// analysis
#include "rooutil.h"
#include "ana.h"
#include "cxxopts.h"

// fastjet
#include "fastjet/ClusterSequence.hh"
#include "fastjet/contrib/SoftDrop.hh"
#include "fastjet/contrib/Nsubjettiness.hh"

namespace util
{
    // Parse input arguments
    void parse_arguments(int argc, char** argv);

    // Initialize analysis (any basic loading prior to looping will be placed here)
    void initialize_analysis();

    // Set cuts to ana::cutflow
    void set_cuts();

    // Create histograms
    void create_histograms();

    // Book histograms
    void book_histograms();

    // Loop over events
    void run_analysis();

    // Create a TTreeX object
    RooUtil::TTreeX create_ttreex();

    // Add outputs to the TTreeX object based on the user options
    void add_ttreex_outputs();

    // Add outputs to the TTreeX object for the BDT (either for creating a training set or to evaluate)
    void add_bdt_ttreex_outputs();

    // Add outputs related to the jet reclustering studies
    void add_reclustering_study_ttreex_outputs();

    // Add slim ttreex outputs
    void add_slim_ttreex_outputs();

    //
    // Jet clustering related functions
    //

    // Create slim ttree
    void make_slim_ttree();

    // Do various things related to running jet clustering ourselves in order to study
    void run_study_reclustering();

    // Do clusterinng where the input: particles is a list of Pseudo jets (constituents such as PF or calo clusters etc.)
    fastjet::ClusterSequence cluster_jets(std::vector<fastjet::PseudoJet> particles, double R, fastjet::JetAlgorithm jetalgo=fastjet::antikt_algorithm);

    // Get a vector of pseudojets with PF candidates around the candidate fat-jet from hww baby
    std::vector<fastjet::PseudoJet> get_particles(bool subtract_lepton, bool do_not_subtract_puppi=false, bool log_subtracted_lepton=false);

    // Perform SoftDrop grooming and return the groomed PseudoJet
    fastjet::PseudoJet get_softdrop_jet(fastjet::PseudoJet&);
}

// For easy printing of fastjet::PseudoJet to std::cout
ostream & operator<<(ostream & ostr, const fastjet::PseudoJet & jet);

// For turning PseudoJet to LV
LV getLV(fastjet::PseudoJet&);

#endif
