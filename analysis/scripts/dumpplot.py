#!/bin/env python

import plottery_wrapper as p
import sys

import argparse

parser = argparse.ArgumentParser(description="Plot dumper from Run 2 Boosted Higgs Analysis")
parser.add_argument('-i' , '--input_dir'  , dest='input_dir'  , help='input dir path (where hists are)'                               , required=True      ) 
parser.add_argument('-o' , '--output_dir' , dest='output_dir' , help='output dir path'                        , default='plots'                            ) 
parser.add_argument('-n' , '--nbins'      , dest='nbins'      , help='number of bins for the histograms'      , default=30                                 ) 
parser.add_argument('-y' , '--yaxis_range', dest='yaxis_range', help='Y-axis range set by user'               , default=None                               ) 
parser.add_argument('-l' , '--yaxis_log'  , dest='yaxis_log'  , help='Y-axis set to log'                      , default=False         , action='store_true') 
parser.add_argument('-s' , '--sig_scale'  , dest='sig_scale'  , help='Signal scale'                           , default=-1                                 ) 

parser.add_argument('filter_patterns', metavar='FILTER_PATTERN', type=str, nargs='+', help='patterns to use to filter histograms to dump')

args = parser.parse_args()

print args

if args.sig_scale < 0:
    sig_scale = "auto"
else:
    sig_scale = float(args.sig_scale)

filter_pattern = ','.join(args.filter_patterns)

input_path_dir = args.input_dir

bkg_fnames = [
        "{}/merged/TT_merged.root".format(input_path_dir),
        "{}/merged/W_merged.root".format(input_path_dir),
        "{}/merged/WW_merged.root".format(input_path_dir),
        "{}/merged/QCD_merged.root".format(input_path_dir),
        ]

sig_fnames = [
        "{}/merged/higgs.root".format(input_path_dir),
        #"{}/merged/VBFHToWWToLNuQQ_merged.root".format(output_path_dir),
        # "outputs/HWW2016_v5.0.0/test15/merged/VHToNonbb_merged.root",
        ]

p.dump_plot(
        dirname=args.output_dir,
        fnames=bkg_fnames,
        sig_fnames=sig_fnames,
        filter_pattern=filter_pattern,
        signal_scale=sig_scale,
        extraoptions={
            "nbins":int(args.nbins),
            "print_yield":True,
            "yaxis_log":args.yaxis_log,
            "yaxis_range":args.yaxis_range.split(',') if args.yaxis_range else [],
            },
        # _plotter=p.plot_cut_scan,
        )
