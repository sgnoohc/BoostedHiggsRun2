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

    jobs = [

            {"sample" : DirectorySample(
                location = "/hadoop/cms/store/user/phchang/metis/private/GluGluHToWWLNuQQ_M125/miniaod/GluGluHToWWToLNuQQ_M125_13TeV_powheg_JHUGenV628_pythia8_Private-ext1_MINIAODSIM_/",
                globber = "*.root",
                dataset = "/GluGluHToWWToLNuQQ_M125_13TeV_powheg_JHUGenV628_pythia8/cms4-Private80X-v1-ext1/MINIAODSIM",
                gtag = "80X_mcRun2_asymptotic_2016_TrancheIV_v6",
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_8_0_26_patch1",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V08-00-06_826p1.tar.gz",
                "tag"         : "CMS4_V08-00-06_826p1_AllPF",
                "pset"        : "pset_moriondremc.py",
                "special_dir" : "run2_80x_cms4_hww/ProjectMetis",
                },

            {"sample" : DBSSample(
                dataset = "/VBFHToWWToLNuQQ_M125_13TeV_powheg_JHUGenV628_pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM",
                xsec=0.355055,
                kfact=1.0,
                efact=1.0,
                # allow_invalid_files=allow_invalid_files,
                allow_invalid_files=False,
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_8_0_26_patch1",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V08-00-06_826p1.tar.gz",
                "tag"         : "CMS4_V08-00-06_826p1_AllPF",
                "pset"        : "pset_moriondremc.py",
                "special_dir" : "run2_80x_cms4_hww/ProjectMetis",
                },

            {"sample" : DBSSample(
                dataset = "/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v1/MINIAODSIM",
                xsec=730.0,
                kfact=1.139397,
                efact=1.0,
                # allow_invalid_files=allow_invalid_files,
                allow_invalid_files=False,
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_9_4_9",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V09-04-17_949.tar.gz",
                "tag"         : "CMS4_V09-04-17_AllPF",
                "pset"        : "pset_mc2016_94x_v3.py",
                "special_dir" : "run2_94x_cms4_hww/ProjectMetis",
                },

            {"sample" : DBSSample(
                dataset = "/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3-v2/MINIAODSIM",
                xsec=1379,
                kfact=1.21,
                efact=1.0,
                # allow_invalid_files=allow_invalid_files,
                allow_invalid_files=False,
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_9_4_9",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V09-04-17_949.tar.gz",
                "tag"         : "CMS4_V09-04-17_AllPF",
                "pset"        : "pset_mc2016_94x_v3.py",
                "special_dir" : "run2_94x_cms4_hww/ProjectMetis",
                },

            {"sample" : DBSSample(
                dataset = "/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3_ext2-v2/MINIAODSIM",
                xsec=359.7,
                kfact=1.21,
                efact=1.0,
                # allow_invalid_files=allow_invalid_files,
                allow_invalid_files=False,
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_9_4_9",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V09-04-17_949.tar.gz",
                "tag"         : "CMS4_V09-04-17_AllPF",
                "pset"        : "pset_mc2016_94x_v3.py",
                "special_dir" : "run2_94x_cms4_hww/ProjectMetis",
                },

            {"sample" : DBSSample(
                dataset = "/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3_ext1-v2/MINIAODSIM",
                xsec=48.91,
                kfact=1.21,
                efact=1.0,
                # allow_invalid_files=allow_invalid_files,
                allow_invalid_files=False,
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_9_4_9",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V09-04-17_949.tar.gz",
                "tag"         : "CMS4_V09-04-17_AllPF",
                "pset"        : "pset_mc2016_94x_v3.py",
                "special_dir" : "run2_94x_cms4_hww/ProjectMetis",
                },

            {"sample" : DBSSample(
                dataset = "/WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3_ext1-v2/MINIAODSIM",
                xsec=12.05,
                kfact=1.21,
                efact=1.0,
                # allow_invalid_files=allow_invalid_files,
                allow_invalid_files=False,
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_9_4_9",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V09-04-17_949.tar.gz",
                "tag"         : "CMS4_V09-04-17_AllPF",
                "pset"        : "pset_mc2016_94x_v3.py",
                "special_dir" : "run2_94x_cms4_hww/ProjectMetis",
                },

            {"sample" : DBSSample(
                dataset = "/WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3_ext1-v2/MINIAODSIM",
                xsec=5.501,
                kfact=1.21,
                efact=1.0,
                # allow_invalid_files=allow_invalid_files,
                allow_invalid_files=False,
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_9_4_9",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V09-04-17_949.tar.gz",
                "tag"         : "CMS4_V09-04-17_AllPF",
                "pset"        : "pset_mc2016_94x_v3.py",
                "special_dir" : "run2_94x_cms4_hww/ProjectMetis",
                },

            {"sample" : DBSSample(
                dataset = "/WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3_ext1-v2/MINIAODSIM",
                xsec=1.329,
                kfact=1.21,
                efact=1.0,
                # allow_invalid_files=allow_invalid_files,
                allow_invalid_files=False,
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_9_4_9",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V09-04-17_949.tar.gz",
                "tag"         : "CMS4_V09-04-17_AllPF",
                "pset"        : "pset_mc2016_94x_v3.py",
                "special_dir" : "run2_94x_cms4_hww/ProjectMetis",
                },

            {"sample" : DBSSample(
                dataset = "/WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/RunIISummer16MiniAODv3-PUMoriond17_94X_mcRun2_asymptotic_v3_ext1-v2/MINIAODSIM",
                xsec=0.03216,
                kfact=1.21,
                efact=1.0,
                # allow_invalid_files=allow_invalid_files,
                allow_invalid_files=False,
                ),
                "pset_args"   : "data=False",
                "cmsswver"    : "CMSSW_9_4_9",
                "tarfile"     : "/nfs-7/userdata/libCMS3/lib_CMS4_V09-04-17_949.tar.gz",
                "tag"         : "CMS4_V09-04-17_AllPF",
                "pset"        : "pset_mc2016_94x_v3.py",
                "special_dir" : "run2_94x_cms4_hww/ProjectMetis",
                },

            ]

    for i in range(10000):

        total_summary = {}
        for job in jobs:

            pset_args = job["pset_args"]
            cmsswver = job["cmsswver"]
            tarfile = job["tarfile"]

            try:

                task = CMSSWTask(
                        sample = job["sample"],
                        output_name = "merged_ntuple.root",
                        tag = job["tag"],
                        global_tag = "", # if global tag blank, one from DBS is used ## NOT USED FOR PRIVATE
                        pset = job["pset"],
                        pset_args = pset_args,
                        cmssw_version = cmsswver,
                        tarfile = tarfile,
                        special_dir = job["special_dir"],
                        publish_to_dis = False,
                        condor_submit_params = {"sites":"T2_US_UCSD"} if isinstance(job["sample"], DirectorySample) else {"use_xrootd":True},
                        files_per_output = 60 if isinstance(job["sample"], DirectorySample) else -1,
                        events_per_output = 50e3 if isinstance(job["sample"], DBSSample) else -1,
                        min_completion_fraction = 0.98 if isinstance(job["sample"], DBSSample) else 1.0,
                )
            
                task.process()
            except:
                traceback_string = traceback.format_exc()
                print "Runtime error:\n{0}".format(traceback_string)

            total_summary[job["sample"].get_datasetname()] = task.get_task_summary()

        StatsParser(data=total_summary, webdir="~/public_html/dump/metis_private/").do()

        time.sleep(60.*20)

