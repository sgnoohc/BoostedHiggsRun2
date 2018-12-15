import time
import itertools
import json
import traceback

from metis.Sample import DBSSample, DirectorySample
from metis.CMSSWTask import CMSSWTask
from metis.StatsParser import StatsParser
from metis.Utils import send_email
from metis.Constants import Constants


if __name__ == "__main__":


    samples = [

            DirectorySample(
                location = "/hadoop/cms/store/user/phchang/metis/private/GluGluHToWWLNuQQ_M125/miniaod/GluGluHToWWToLNuQQ_M125_13TeV_powheg_JHUGenV628_pythia8_Private-ext1_MINIAODSIM_/",
                globber = "*.root",
                dataset = "/GluGluHToWWToLNuQQ_M125_13TeV_powheg_JHUGenV628_pythia8/cms4-Private80X-v1-ext1/MINIAODSIM",
                gtag = "80X_mcRun2_asymptotic_2016_TrancheIV_v6",
                ),

            ]

    for i in range(10000):

        total_summary = {}
        for sample in samples:

            pset_args = "data=False"
            cmsswver = "CMSSW_8_0_26_patch1"
            tarfile = "/nfs-7/userdata/libCMS3/lib_CMS4_V08-00-06_826p1.tar.gz"

            try:

                task = CMSSWTask(
                        sample = sample,
                        output_name = "merged_ntuple.root",
                        tag = "CMS4_V08-00-06_826p1",
                        global_tag = "", # if global tag blank, one from DBS is used ## NOT USED FOR PRIVATE
                        pset = "pset_moriondremc.py",
                        pset_args = pset_args,
                        cmssw_version = cmsswver,
                        tarfile = tarfile,
                        special_dir = "run2_80x_cms4_hww/ProjectMetis",
                        publish_to_dis = False,
                        condor_submit_params = {"sites":"T2_US_UCSD"} if isinstance(sample, DirectorySample) else {"use_xrootd":True},
                        files_per_output = 60 if isinstance(sample, DirectorySample) else -1,
                        events_per_output = 50e3 if isinstance(sample, DBSSample) else -1,
                        min_completion_fraction = 0.98 if isinstance(sample, DBSSample) else 1.0,
                )
            
                task.process()
            except:
                traceback_string = traceback.format_exc()
                print "Runtime error:\n{0}".format(traceback_string)

            total_summary[sample.get_datasetname()] = task.get_task_summary()

        StatsParser(data=total_summary, webdir="~/public_html/dump/metis_private/").do()

        time.sleep(60.*20)

