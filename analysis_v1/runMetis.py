##!/bin/env python

import rooutil as ru
import glob
import os
import sys

def main():

    if len(sys.argv) > 1:
        force = True
    else:
        force = False

    job_tag = "test55_20190312"
    input_ntup_tag = "HWW2016_v5.0.3"
    base_dir_path = "/hadoop/cms/store/user/phchang/metis/baby/{}/".format(input_ntup_tag)
    tar_files = ["doAnalysis", "setup.sh", "fastjet"]
    hadoop_dirname = "hwwanalysis"

    if force:
        os.system("rm -rf outputs/{}/{}".format(input_ntup_tag, job_tag))
        os.system("rm -rf /hadoop/cms/store/user/phchang/metis/{}/{}/{}".format(hadoop_dirname, input_ntup_tag, job_tag))
        os.system('mclean --rm "*"')
        os.system("rm -rf ProjectMetis/tasks/*_{}".format(job_tag))

    all_samples = glob.glob("{}/*".format(base_dir_path))

    samples_map = {}
    files_per_output_map = {}
    for sample in all_samples:
        # if "Glu" not in sample:
        #     continue
        if "Single" in sample:
            continue
        sample_rawname = os.path.basename(sample)
        sample_name = sample_rawname.replace("MAKER_", "").replace("_{}".format(input_ntup_tag), "")
        if "M125" in sample_name:
            sample_name = sample_name.split("_M125")[0]
        else:
            sample_name = sample_name.split("_Tune")[0]
        samples_map[sample_name] = sample

        # Taking care of files_per_output
        if "M125" in sample_name:
            files_per_output_map[sample_name] = 30
        elif "TT" in sample_name:
            files_per_output_map[sample_name] = 15
        elif "WJets" in sample_name:
            files_per_output_map[sample_name] =  5
        elif "WW" in sample_name:
            files_per_output_map[sample_name] = 30
        elif "QCD" in sample_name:
            files_per_output_map[sample_name] = 30
        else:
            files_per_output_map[sample_name] = 30

    ru.submit_metis(job_tag, samples_map, tar_files=tar_files, hadoop_dirname=hadoop_dirname+"/"+input_ntup_tag, files_per_output=files_per_output_map, sites="T2_US_UCSD")

    #os.system("mkdir -p outputs/condor/{}/{}/".format(input_ntup_tag, job_tag))

    for sample_name in samples_map:

        # Directory holding all the histogram outputs
        dir_path = "/hadoop/cms/store/user/phchang/metis/hwwanalysis/{}/{}/{}_{}".format(input_ntup_tag, job_tag, sample_name, job_tag)

        # Create output dir
        output_dir_path = "outputs/{}/{}/merged/".format(input_ntup_tag, job_tag)
        os.system("mkdir -p {}".format(output_dir_path))

        # Hadd command
        output_file_prefix = "{}/{}_merged".format(output_dir_path, sample_name)
        output_file_name = "{}.root".format(output_file_prefix)
        cmd = "if [ ! -f {} ]; then addHistos.sh {} {}/output {} 4; fi".format(output_file_name, output_file_prefix, dir_path, len(glob.glob(dir_path + "/*.root")))
        print cmd
        os.system(cmd)

    # W+jets
    cmd = "if [ ! -f {}/W_merged.root ]; then hadd {}/W_merged.root {}/WJets*merged.root; fi".format(output_dir_path, output_dir_path, output_dir_path)
    print cmd
    os.system(cmd)

    # higgs
    cmd = "if [ ! -f {}/higgs.root ]; then hadd {}/higgs.root {}/GluGlu*_merged.root {}/VH*_merged.root {}/VBF*_merged.root; fi".format(output_dir_path, output_dir_path, output_dir_path, output_dir_path, output_dir_path)
    print cmd
    os.system(cmd)

    # QCD_HT
    cmd = "if [ ! -f {}/QCD_merged.root ]; then hadd {}/QCD_merged.root {}/QCD_HT*merged.root; fi".format(output_dir_path, output_dir_path, output_dir_path)
    print cmd
    os.system(cmd)

if __name__ == "__main__":
    main()

#eof
