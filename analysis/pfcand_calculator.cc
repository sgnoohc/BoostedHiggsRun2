#include "pfcand_calculator.h"

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
float pf_x(unsigned int ii)
{
    float dr    = hww.Htag_pf_dr()   [ii];
    float alpha = hww.Htag_pf_alpha()[ii];
    float L_a   = hww.Htag_L_alpha();
    float x = dr * TMath::Sin(alpha - L_a);
    return x;
}

//_____________________________________________________________________________
float pf_y(unsigned int ii)
{
    float dr    = hww.Htag_pf_dr()   [ii];
    float alpha = hww.Htag_pf_alpha()[ii];
    float L_a   = hww.Htag_L_alpha();
    float y = dr * TMath::Cos(alpha - L_a);
    return y;
}

//_____________________________________________________________________________
// Per PF candidate the proper weight is the pf * puppi_wgt
float pf_wgt(unsigned int ii)
{
    float w = hww.Htag_pf_ptfrac()[ii] * hww.Htag_pf_puppi_wgt()[ii];
    return w;
}

//_____________________________________________________________________________
// This is a temporary binning for the grid for an input to the BDT as a first
// try for HWW tagger The binnings were chosen after looking at the image of an
// averaged PF candidate distribution These are extremely preliminary and could
// be improved upon in the future The big-picture idea is that we are trying to
// take an image of the tagged J ak8jets from PF candidates around it
int bdt_bin(unsigned int ii)
{

    float x = pf_x(ii);
    float y = pf_y(ii);

    // These boundaries are susceptible to higgs pt in principle....
    // y-axis = -0.5, -0.2, -0.1, -0.01, 0.1, 0.5
    // x-axis = -0.5, -0.16, -0.04, 0.04, 0.16, 0.5
    if      (x > -0.5  and x < -0.16 and y > -0.01 and y < 0.5 ) { return 1; }
    else if (x > -0.16 and x < -0.04 and y >  0.1  and y < 0.5 ) { return 2; }
    else if (x > -0.04 and x <  0.04 and y >  0.1  and y < 0.5 ) { return 3; }
    else if (x >  0.04 and x <  0.16 and y >  0.1  and y < 0.5 ) { return 4; }
    else if (x >  0.16 and x <  0.5  and y > -0.01 and y < 0.5 ) { return 5; }
    else if (x > -0.16 and x < -0.04 and y > -0.01 and y < 0.1 ) { return 6; }
    else if (x > -0.04 and x <  0.04 and y > -0.01 and y < 0.1 ) { return 7; }
    else if (x >  0.04 and x <  0.16 and y > -0.01 and y < 0.1 ) { return 8; }
    else if (x > -0.16 and x < -0.04 and y > -0.1  and y <-0.01) { return 9; }
    else if (x > -0.04 and x <  0.04 and y > -0.1  and y <-0.01) { return 10; }
    else if (x >  0.04 and x <  0.16 and y > -0.1  and y <-0.01) { return 11; }
    else if (x > -0.16 and x < -0.04 and y > -0.2  and y <-0.1 ) { return 12; }
    else if (x > -0.04 and x <  0.04 and y > -0.2  and y <-0.1 ) { return 13; }
    else if (x >  0.04 and x <  0.16 and y > -0.2  and y <-0.1 ) { return 14; }
    else if (x > -0.5  and x < -0.16 and y > -0.5  and y <-0.01) { return 15; }
    else if (x > -0.16 and x <  0.16 and y > -0.5  and y <-0.2 ) { return 16; }
    else if (x >  0.16 and x <  0.5  and y > -0.5  and y <-0.01) { return 17; }
    else                                                         { return 18; }

}

//_____________________________________________________________________________
// This loops over the PF candidates and sums up the weights per input grid bin
// and return a vector<float> that has the each input grid's summed pt weight
std::vector<float> get_bdt_bin_contents()
{

    std::vector<float> bin_contents;

    for (unsigned int ii = 0; ii < 18; ++ii)
    {
        bin_contents.push_back(0);
    }

    std::cout <<  " hww.Htag_pf_dr().size(): " << hww.Htag_pf_dr().size() <<  std::endl;
    float sumpt = 0;
    float sumptpuppi = 0;
    for (unsigned int ii = 0; ii < hww.Htag_pf_dr().size(); ++ii)
    {
        int ibin = bdt_bin(ii);
        // float wgt = pf_wgt(ii);
        std::cout <<  " pf_x(ii): " << pf_x(ii) <<  " pf_y(ii): " << pf_y(ii) <<  " hww.Htag_pf_ptfrac()[ii]: " << hww.Htag_pf_ptfrac()[ii] <<  " hww.Htag_pf_puppi_wgt()[ii]: " << hww.Htag_pf_puppi_wgt()[ii] <<  " hww.Htag_fromPV()[ii]: " << hww.Htag_fromPV()[ii] <<  std::endl;
        bin_contents[ibin] += pf_wgt(ii);
        sumpt      += hww.Htag_pf_ptfrac()[ii] * hww.J_p4().pt() * (hww.Htag_fromPV()[ii] >= 2);
        sumptpuppi += hww.Htag_pf_ptfrac()[ii] * hww.J_p4().pt() * hww.Htag_pf_puppi_wgt()[ii];
        // std::cout <<  " ibin: " << ibin <<  " bin_contents[ibin]: " << bin_contents[ibin] <<  " wgt: " << wgt <<  std::endl;
    }
    std::cout <<  " sumpt: " << sumpt <<  " sumptpuppi: " << sumptpuppi <<  " hww.J_p4().pt(): " << hww.J_p4().pt() <<  " hww.L_p4().pt(): " << hww.L_p4().pt() <<  std::endl;

    return bin_contents;

}

