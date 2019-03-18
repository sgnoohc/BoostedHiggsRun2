#!/bin/env python

import rooutil as ru
import plottery_wrapper as p
import glob

class HWWHists:

    def __init__(self, bgs_sigs, bgs, sigs):

        self.bgs_sigs = bgs_sigs
        self.bgs = bgs
        self.sigs = sigs

    def add_list_of_histograms(self, l1, l2):

        new_list = []

        for i, j in zip(l1, l2):
            new_list.append(i.Clone())
            new_list[-1].Reset()
            new_list[-1].Add(i)
            new_list[-1].Add(j)

        return new_list

    def clone_list_of_histograms(self, l1):

        new_list = []

        for i in l1:
            new_list.append(i.Clone())

        return new_list

    def __add__(self, other):

        new_bgs_sigs = self.add_list_of_histograms(self.bgs_sigs, other.bgs_sigs)
        new_bgs = self.add_list_of_histograms(self.bgs, other.bgs)
        new_sigs = self.add_list_of_histograms(self.sigs, other.sigs)

        return HWWHists(new_bgs_sigs, new_bgs, new_sigs)

    def clone(self):

        new_bgs_sigs = self.clone_list_of_histograms(self.bgs_sigs)
        new_bgs = self.clone_list_of_histograms(self.bgs)
        new_sigs = self.clone_list_of_histograms(self.sigs)

        return HWWHists(new_bgs_sigs, new_bgs, new_sigs)


def get_hists(histnames):

    #output_dirpath = "outputs/HWW2016_v5.0.1/test46_20180303/merged" # full selection
    #output_dirpath = "outputs/HWW2016_v5.0.1/test47_20180303/merged" # without QQ mass

    output_dirpath = "outputs/HWW2016_v5.0.1/test66_20180306/merged" # without QQ mass
    output_dirpath = "outputs/HWW2016_v5.0.2/test71_20180306/merged" # without QQ mass
    output_dirpath = "outputs/HWW2016_v5.0.3/test_20180307/merged" # without QQ mass
    output_dirpath = "outputs/HWW2016_v5.0.3/test49_20180308/merged" # without QQ mass

    suffix = "*MINIAODSIM"
    suffix = "_merged"

    bkg_list_ttbar = glob.glob(output_dirpath+"/TT"+suffix+".root")
    bkg_list_wjets = glob.glob(output_dirpath+"/W"+suffix+".root")
    bkg_list_ww    = glob.glob(output_dirpath+"/WW"+suffix+".root")
    #bkg_list_nonvh = glob.glob(output_dirpath+"/Glu"+suffix+".root") + glob.glob(output_dirpath+"/VBF"+suffix+".root")
    bkg_list_higgs = glob.glob(output_dirpath+"/higgs.root")
    #bkg_list_higgs = glob.glob(output_dirpath+"/GluGluHToWWToLNuQQ"+suffix+".root") + glob.glob(output_dirpath+"/VBFHToWWToLNuQQ"+suffix+".root")
    #bkg_list_higgs = glob.glob(output_dirpath+"/GluGluHToWWToLNuQQ"+suffix+".root")
    #bkg_list_higgs = glob.glob(output_dirpath+"/VBFHToWWToLNuQQ"+suffix+".root")
    #bkg_list_higgs = glob.glob(output_dirpath+"/VHToNonbb"+suffix+".root")
    bkg_list_ggf   = glob.glob(output_dirpath+"/GluGluHToWWToLNuQQ"+suffix+".root")
    bkg_list_vbf   = glob.glob(output_dirpath+"/VBFHToWWToLNuQQ"+suffix+".root")
    bkg_list_vh    = glob.glob(output_dirpath+"/VHToNonbb"+suffix+".root")
    # data_list      = glob.glob(output_dirpath+"/*Run2017*")
    bkg_list_qcd   = glob.glob(output_dirpath+"/QCD_HT*"+suffix+".root")
    # bkg_list_qcd   = glob.glob(output_dirpath+"/QCD*-470*"+suffix+".root")
    # bkg_list_qcd   = glob.glob(output_dirpath+"/QCD*-300*"+suffix+".root")

    hists = {}
    if len(bkg_list_wjets) > 0: hists["wjets"] = ru.get_summed_histogram(bkg_list_wjets , histnames)
    if len(bkg_list_ttbar) > 0: hists["ttbar"] = ru.get_summed_histogram(bkg_list_ttbar , histnames)
    if len(bkg_list_ww   ) > 0: hists["ww"]    = ru.get_summed_histogram(bkg_list_ww    , histnames)
    if len(bkg_list_qcd  ) > 0: hists["qcd"]   = ru.get_summed_histogram(bkg_list_qcd   , histnames)
    if len(bkg_list_higgs) > 0: hists["higgs"] = ru.get_summed_histogram(bkg_list_higgs , histnames)
    if len(bkg_list_ggf  ) > 0: hists["ggf"]   = ru.get_summed_histogram(bkg_list_ggf   , histnames)
    if len(bkg_list_vbf  ) > 0: hists["vbf"]   = ru.get_summed_histogram(bkg_list_vbf   , histnames)
    if len(bkg_list_vh   ) > 0: hists["vh"]    = ru.get_summed_histogram(bkg_list_vh    , histnames)
    # if len(data_list     ) > 0: hists["data"]  = ru.get_summed_histogram(data_list      , histnames)

    if "wjets" in hists: hists["wjets"].SetName("W")
    if "ww"    in hists: hists["ww"]   .SetName("WW")
    if "qcd"   in hists: hists["qcd"]   .SetName("QCD")
    if "ttbar" in hists: hists["ttbar"].SetName("t#bar{t}")
    #if "higgs" in hists: hists["higgs"].SetName("ggF+VBF+VH")
    if "higgs" in hists: hists["higgs"].SetName("ggF+VBF")
    if "ggf"   in hists: hists["ggf"]  .SetName("ggF")
    if "vbf"   in hists: hists["vbf"]  .SetName("VBF")
    if "vh"    in hists: hists["vh"]   .SetName("VH")
    # if "data"  in hists: hists["data"] .SetName("Data")

    # if "ww"    in hists: hists["ww"]   .Scale(0)
    # if "ggf"   in hists: hists["ggf"]  .Scale(1.3)
    # if "vbf"   in hists: hists["vbf"]  .Scale(109)
    # if "vh"    in hists: hists["vh"]   .Scale(1)
    # hists["higgs"].Reset()
    # hists["higgs"].Add(hists["ggf"])
    # hists["higgs"].Add(hists["vbf"])
    # hists["higgs"].Add(hists["vh"])

    # hists["ww"].Scale(0)

    bkg_lists = [ "qcd", "ww", "ttbar", "wjets", "higgs" ]
    bkg_hists = [ hists[x].Clone() for x in bkg_lists if x in hists ]
    sig_lists = [ "higgs", "vh" ]
    sig_lists = [ "higgs"]
    sig_hists = [ hists[x].Clone() for x in sig_lists if x in hists ]
    bkg_sig_lists = [ "qcd", "ww", "ttbar", "wjets", "higgs" ]
    bkg_sig_hists = [ hists[x].Clone() for x in bkg_sig_lists if x in hists ]

    bgs = bkg_hists if len(bkg_hists) > 0 else sig_hists
    bgs_sigs = bkg_sig_hists if len(bkg_sig_hists) > 0 else sig_hists
    sigs = sig_hists if len(bkg_hists) > 0 else []

    return HWWHists(bgs_sigs, bgs, sigs)

def plot(hwwhists, output_name, extraoptions):

    bgs = hwwhists.clone().bgs
    bgs_sigs = hwwhists.clone().bgs_sigs
    sigs = hwwhists.clone().sigs

    colors = [ 2004, 2003, 2005, 2001, 2, 4 ] if len(bgs) > 0 else [ 2, 4 ]

    alloptions= {
                "ratio_range":[0.0,2.0],
                "nbins": 180,
                "autobin": False,
                "legend_scalex": 1.8,
                "legend_scaley": 1.1,
                "output_name": "plots/scan/{}.pdf".format(output_name),
                "bkg_sort_method": "unsorted",
                "no_ratio": True,
                "print_yield": False,
                # "yaxis_range": [0, 0.002],
                }
    alloptions.update(extraoptions)

    # # Run scan only if the both sig and bkg exists
    # if len(bgs) > 0 and len(sigs) > 0:
    #     p.plot_cut_scan(
    #             bgs = bgs,
    #             sigs = sigs,
    #             data = None,
    #             colors = colors,
    #             syst = None,
    #             options=alloptions)

    bgs = hwwhists.clone().bgs
    bgs_sigs = hwwhists.clone().bgs_sigs
    sigs = hwwhists.clone().sigs

    alloptions= {
                "ratio_range":[0.0,2.0],
                "nbins": 60,
                "autobin": False,
                "legend_scalex": 1.8,
                "legend_scaley": 1.1,
                "output_name": "plots/lin/{}.pdf".format(output_name),
                "bkg_sort_method": "unsorted",
                "no_ratio": True,
                "print_yield": True,
                "signal_scale": 1 if "yield" in output_name or "cutflow" in output_name else "auto",
                # "divide_by_first_bin": True if "cutflow" in output_name else False,
                "yield_prec": 3 if "cutflow" in output_name else 3,
                #"yaxis_range": [0., 500],
                }
    alloptions.update(extraoptions)

    p.plot_hist(
            bgs  = bgs_sigs,
            sigs = sigs,
            data = None,
            colors = colors,
            syst = None,
            options=alloptions)

    bgs = hwwhists.clone().bgs
    bgs_sigs = hwwhists.clone().bgs_sigs
    sigs = hwwhists.clone().sigs

    alloptions= {
                "ratio_range":[0.0,2.0],
                "nbins": 60,
                "autobin": False,
                "legend_scalex": 1.8,
                "legend_scaley": 1.1,
                "output_name": "plots/log/{}.pdf".format(output_name),
                "bkg_sort_method": "unsorted",
                "no_ratio": True,
                "print_yield": False,
                "signal_scale": 1 if "yield" in output_name or "cutflow" in output_name else "auto",
                # "divide_by_first_bin": True if "cutflow" in output_name else False,
                "yaxis_log": True,
                "legend_smart": False,
                }
    alloptions.update(extraoptions)

    p.plot_hist(
            bgs  = bgs_sigs,
            sigs = sigs,
            data = None,
            colors = colors,
            syst = None,
            options=alloptions)

def quick_plot(variable):
    h1 = get_hists("CutISR450MuMinusHad__{}".format(variable))
    # h2 = get_hists("CutISR450MuPlusHad__{}".format(variable))
    # h1 = get_hists("CutISR450MuMinusLep__{}".format(variable))
    # h2 = get_hists("CutISR450MuPlusLep__{}".format(variable))
    plot(h1, variable)

def quick_plot_v2(histnames, outputname, extraoptions={}):

    h = None
    for histname in histnames:
        if h:
            h += get_hists(histname)
        else:
            h = get_hists(histname)
    plot(h, outputname, extraoptions)



def main():

    # quick_plot_v2(["CutISR400MuMinusHad__dr_L_QQ"], "dr_L_QQ");
    # quick_plot_v2(["CutISR400MuMinusHad__dr_L_QQp"], "dr_L_QQp");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__J_mass"], "J_mass");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__dr_L_QQ"], "dr_L_QQ_after");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2__L_customrelIso005EA_zoom"], "L_customrelIso005EA_zoom");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2__L_customrelIso005EA"], "L_customrelIso005EA");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2__J_mass"], "J_mass_after");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut3__mljreg"], "mljreg");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut3__L_customrelIso005EA"], "L_customrelIso005EA_after");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut4__RecoH_mass_minsol12"], "RecoH_mass_minsol12");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut4__mljreg"], "mljreg_after");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__isrbalance"], "isrbalance");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__isrbalancev2"], "isrbalancev2");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__RecoH_mass_minsol12"], "RecoH_mass_minsol12_after");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__QQ_mass"], "QQ_mass");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__isrbalance"], "isrbalance");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2__J_mass"], "J_mass");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut3__L_customrelIso005EA_zoom"], "L_customrelIso005EA_zoom");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut4__RecoH_mass_minsol12"], "RecoH_mass_minsol12");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__mljreg"], "mljreg");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__isrbalance"], "isrbalance");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut7_cutflow"], "cutflow");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut7__yield"], "yield");

    # quick_plot_v2(["CutISR400MuMinusHad__QQ_mass"], "QQ_mass");
    # quick_plot_v2(["CutISR400MuMinusHad__QQp_mass"], "QQp_mass");
    # quick_plot_v2(["CutISR400MuMinusHad__J_softdropMass"], "J_softdropMass");
    # quick_plot_v2(["CutISR400MuMinusHad__QQ_mass_SD"], "QQ_mass_SD");
    # quick_plot_v2(["CutISR400MuMinusHad__QQ_mass_v2"], "QQ_mass_v2");
    # quick_plot_v2(["CutISR400MuMinusHad__QQ_mass_SDv2"], "QQ_mass_SDv2");
    # quick_plot_v2(["CutISR400MuMinusHad__J_mass"], "J_mass");
    # quick_plot_v2(["CutISR400MuMinusHad__QQp_mass"], "QQp_mass");

    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__L_relIso04DB"], "L_relIso04DB");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__L_customrelIso010EA_zoom"], "L_customrelIso010EA_zoom");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__L_customrelIso005EA_zoom"], "L_customrelIso005EA_zoom");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__mljreg"], "mljreg");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__RecoH_mass_minsol12"], "RecoH_mass_minsol12");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__yield"], "yield");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__mljak4"], "mljak4");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__isrbalance"], "isrbalance");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut1__isrbalancev2"], "isrbalancev2");

    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2A__RecoH_mass_minsol12"], "RecoH_mass_minsol12");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2B__L_relIso04DB"], "L_relIso04DB");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2B__L_customrelIso005EA_zoom"], "L_customrelIso005EA_zoom");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2B__yield"], "yield");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2B__J_mass"], "J_mass");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2B__J_softdropMass"], "J_softdropMass");

    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__drlj"], "drlj");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__detalj"], "detalj");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__dphilj"], "dphilj");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__drlj2"], "drlj2", {"yaxis_range":[0.,300]});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__detalj2"], "detalj2", {"yaxis_range":[0.,300]});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__dphilj2"], "dphilj2", {"yaxis_range":[0.,300]});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__drlj3"], "drlj3")
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__detalj3"], "detalj3")
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut5__dphilj3"], "dphilj3")
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__yield"], "yield");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__yield"], "yield");
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__QQ_mass"], "QQ_mass", {"nbins":45, "signal_scale": 5});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__QQ_mass_zoom"], "QQ_mass_zoom", {"nbins": 10, "signal_scale": 5});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__QQ_mass_zoomzoom"], "QQ_mass_zoomzoom", {"nbins": 6, "remove_underflow":True, "signal_scale": 5});

    # for i in xrange(18):
    #     quick_plot_v2(["CutISR400MuMinusLep__BDT_v1_{}".format(i)], "BDT_v1_{}".format(i));

    # for i in xrange(13):
    #     quick_plot_v2(["CutISR400MuMinusLep__BDT_v2_{}".format(i)], "BDT_v2_{}".format(i));

    # output_dirpath = "outputs/HWW2016_v5.0.1/test55_20180303/merged" # without QQ mass
    # p.dump_plot(
    #         [
    #             output_dirpath + "/GluGluHToWWToLNuQQ_merged.root",
    #             output_dirpath + "/TT_merged.root",
    #             output_dirpath + "/W_merged.root",
    #             output_dirpath + "/WW_merged.root",
    #         ], donorm=True, filter_pattern="image", dirname="plots_full_lego")
    # p.dump_plot(
    #         [
    #             output_dirpath + "/GluGluHToWWToLNuQQ_merged.root",
    #             output_dirpath + "/TT_merged.root",
    #             output_dirpath + "/W_merged.root",
    #             output_dirpath + "/WW_merged.root",
    #         ], donorm=True, filter_pattern="L_dr", dirname="plots_full_lego")

    # quick_plot_v2(["CutISR400MuMinusHad__L_ip3d"], "L_ip3d", {"nbins": 45, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__L_dxy"], "L_dxy", {"nbins": 45, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__L_dz"], "L_dz", {"nbins": 45, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__L_pt"], "L_pt", {"nbins": 60, "signal_scale": "auto"})
    # quick_plot_v2(["CutISR400MuMinusHad__L_miniIsoEA"], "L_miniIsoEA", {"nbins": 60, "signal_scale": 2000})
    # quick_plot_v2(["CutISR400MuMinusHad__J_softdropMass"], "J_softdropMass", {"nbins": 60, "signal_scale": 2000})
    # quick_plot_v2(["CutISR400MuMinusHad__BDT_W2"], "BDT_W2", {"nbins": 60, "signal_scale": "auto"})
    # quick_plot_v2(["CutISR400MuMinusHad__BDT_TT2"], "BDT_TT2", {"nbins": 60, "signal_scale": "auto"})
    # quick_plot_v2(["CutISR400MuMinusHad__BDT_Comb"], "BDT_Comb", {"nbins": 60, "signal_scale": "auto"})
    # quick_plot_v2(["CutISR400MuMinusHad__wlep_minus_whad_o_higgs","CutISR400MuMinusLep__wlep_minus_whad_o_higgs"], "wlep_minus_whad_o_higgs", {"nbins": 60, "signal_scale": "auto"})

    # quick_plot_v2(["CutISR400MuMinusHad__BDT_W2"], "BDT_W2", {"nbins": 45, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__BDT_TT2"], "BDT_TT2", {"nbins": 45, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__BDT_Comb"], "BDT_Comb", {"nbins": 45, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__BDT_W"], "BDT_W", {"nbins": 45, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__BDT_TT"], "BDT_TT", {"nbins": 45, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHadMVAW__BDT_TT"], "BDT_TT", {"nbins": 45, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHadMVAW__BDT_TT_zoom"], "BDT_TT_zoom", {"nbins": 6, "signal_scale": 1, "remove_underflow":True})
    # quick_plot_v2(["CutISR400MuMinusHad__BDT_W"], "BDT_W", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__BDT_TT"], "BDT_TT", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHadMVATT__BDT_W"] , "BDT_W" , {"nbins": 10, "signal_scale": 1})
    # quick_plot_v2(["CutISR400MuMinusHadMVATT__dr_L_QQ"] , "dr_L_QQ")
    # quick_plot_v2(["CutISR400MuMinusHadMVATT__J_npfcands"] , "npfcands")
    # quick_plot_v2(["CutISR400MuMinusHadMVATT__J_nJettinessTau1"] , "J_nJettinessTau1")
    # quick_plot_v2(["CutISR400MuMinusHadMVATT__J_nJettinessTau2"] , "J_nJettinessTau2")
    # quick_plot_v2(["CutISR400MuMinusHadMVATT__J_nJettinessTau3"] , "J_nJettinessTau3")
    # quick_plot_v2(["CutISR400MuMinusHadMVATT__L_miniIsoEA"] , "L_miniIsoEA")

    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__Lmet_mt"], "Lmet_mt", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__Lmet_mass"], "Lmet_mass", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__Lmet_pt"], "Lmet_pt", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__met_pt"], "met_pt", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__L_miniIsoEA"], "L_miniIsoEA", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__J_mass"], "J_mass", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__QQ_mass"], "QQ_mass", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__QQ_pt"], "QQ_pt", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__LQQ_mass"], "LQQ_mass", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__L_pt"], "L_pt", {"nbins": 30, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__L_ip3d"], "L_ip3d", {"nbins": 180, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__L_dxy"], "L_dxy", {"nbins": 180, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__isrbalancev2"], "isrbalancev2", {"nbins": 60, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut6__isrbalance"], "isrbalance", {"nbins": 60, "signal_scale": 30});
    # quick_plot_v2(["CutISR400MuMinusHadGenHadOff__QQ_mass"], "QQ_mass", {"nbins": 60, "signal_scale": 100});

    # quick_plot_v2(["CutISR400MuMinusHadStrawManCut2__drlj"], "drlj", {"nbins": 60});

    # quick_plot_v2(["CutISR400MuMinusHad__L_miniIsoEA"], "L_miniIsoEA", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__dr_L_QQ"], "dr_L_QQ", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__isrbalance"], "isrbalance", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__isrbalancev2"], "isrbalancev2", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__dphilj"], "dphilj", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__J_deep_rawdisc_qcd"], "J_deep_rawdisc_qcd", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__recoil_pt"], "recoil_pt", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__nrecolep"], "nrecolep", {"nbins": 60, "signal_scale": 50})
    # quick_plot_v2(["CutISR400MuMinusHad__nak8jets"], "nak8jets", {"nbins": 60, "signal_scale": 50})

    quick_plot_v2(["CutISR400MuMinus__L_pt"], "L_pt", {"nbins": 60, "signal_scale": 50})
    quick_plot_v2(["CutISR400MuMinus__J_pt"], "J_pt", {"nbins": 60, "signal_scale": 50})


if __name__ == "__main__":
    main()
