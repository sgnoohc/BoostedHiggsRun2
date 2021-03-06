#!/bin/bash
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc630
if [ -r CMSSW_9_4_7/src ] ; then 
 echo release CMSSW_9_4_7 already exists
else
scram p CMSSW CMSSW_9_4_7
fi
cd CMSSW_9_4_7/src
eval `scram runtime -sh`


scram b
cd ../../
cmsDriver.py step1 --filein "dbs:/GluGluHToZZTo2L2Q_M125_13TeV_powheg2_JHUGenV7011_pythia8/RunIIFall17DRPremix-PU2017_94X_mc2017_realistic_v11-v2/AODSIM" --fileout file:HIG-RunIIFall17MiniAODv2-02879.root --mc --eventcontent MINIAODSIM --runUnscheduled --datatier MINIAODSIM --conditions 94X_mc2017_realistic_v14 --step PAT --nThreads 4 --scenario pp --era Run2_2017,run2_miniAOD_94XFall17 --python_filename HIG-RunIIFall17MiniAODv2-02879_1_cfg.py --no_exec --customise Configuration/DataProcessing/Utils.addMonitoring -n 4800 || exit $? ; 

