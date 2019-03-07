#!/bin/env python

import plottery_wrapper as p
import sys

if len(sys.argv) > 1:
    filter_pattern = sys.argv[1]
else:
    filter_pattern = "_"

if len(sys.argv) > 2:
    sig_scale = float(sys.argv[1])
else:
    sig_scale = "auto"

print filter_pattern

output_path_dir = "outputs/HWW2016_v5.0.3/test_20180307"

bkg_fnames = [
        "{}/merged/TT_merged.root".format(output_path_dir),
        "{}/merged/W_merged.root".format(output_path_dir),
        "{}/merged/WW_merged.root".format(output_path_dir),
        "{}/merged/QCD_merged.root".format(output_path_dir),
        ]

sig_fnames = [
        "{}/merged/higgs.root".format(output_path_dir),
        #"{}/merged/VBFHToWWToLNuQQ_merged.root".format(output_path_dir),
        # "outputs/HWW2016_v5.0.0/test15/merged/VHToNonbb_merged.root",
        ]

p.dump_plot(
        fnames=bkg_fnames,
        sig_fnames=sig_fnames,
        filter_pattern=filter_pattern,
        signal_scale=sig_scale,
        # extraoptions={"nbins":90, "print_yield":True, "yaxis_log":True, "yaxis_range":[0.1, 1e7]},
        extraoptions={"nbins":30, "print_yield":True},
        # _plotter=p.plot_cut_scan,
        )
