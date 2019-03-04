#ifndef pfcand_calculator_h
#define pfcand_calculator_h

#include <vector>
#include "hwwtree.h"

// ============================================================================
// variable calculation related to the pf candidate location
// ============================================================================

// The pf_x and pf_y function will return the location of the pf candidate wrt
// to the tagged ak8jets (i.e. hww.J_p4()) where the coordinate in eta-phi is
// rotated such that the tagged lepton (L_p4) is on the positive y-axis.
//
// See these slides to get an idea more detail: http://uaf-10.t2.ucsd.edu/~phchang/talks/PhilipChang20190226_HighPtHWW.pdf 
//
// The _alpha's are phi angle in eta-phi space, with nominal coordinate.
// The variable is computed in the baby maker
// Then, take the tagged lepton's alpha as reference and rotate the rest.
// Then, x and y positions are.
// x = dr * sin(pf_alpha - lepton_alpha)
// y = dr * cos(pf_alpha - lepton_alpha)

//_____________________________________________________________________________
float pf_x(unsigned int ii);

//_____________________________________________________________________________
float pf_y(unsigned int ii);

//_____________________________________________________________________________
// Per PF candidate the proper weight is the pf * puppi_wgt
float pf_wgt(unsigned int ii);

//_____________________________________________________________________________
// This is a temporary binning for the grid for an input to the BDT as a first
// try for HWW tagger The binnings were chosen after looking at the image of an
// averaged PF candidate distribution These are extremely preliminary and could
// be improved upon in the future The big-picture idea is that we are trying to
// take an image of the tagged J ak8jets from PF candidates around it
int bdt_bin(unsigned int ii);

//_____________________________________________________________________________
// This loops over the PF candidates and sums up the weights per input grid bin
// and return a vector<float> that has the each input grid's summed pt weight
std::vector<float> get_bdt_bin_contents();

#endif
