#!/bin/bash

VERSION=$1
VERSION=HWW2016_v5.0.1
OUTPUTDIR=outputs/${VERSION}
ISNFS=true
mkdir -p ${OUTPUTDIR}

rm .jobs.txt

if [ $DONFS ]; then
    for f in $(ls /nfs-7/userdata/phchang/babies/${VERSION}/*.root); do
        echo $f
        DIRNAME=$(dirname $f)
        DIRNAME=$(dirname $DIRNAME)
        SAMPLENAME=$(basename $DIRNAME)
        SAMPLENAME=${SAMPLENAME/_MINIAODSIM_${VERSION}/}
        FILENAME=$(basename $f)
        echo $SAMPLENAME
        echo './doAnalysis '$f' '${OUTPUTDIR}'/'${SAMPLENAME}${FILENAME}' -1 > '${OUTPUTDIR}'/'${SAMPLENAME}${FILENAME}'.log 2>&1' >> .jobs.txt
    done
else
    #for f in $(ls /hadoop/cms/store/user/phchang/metis/baby/${VERSION}/*/merged/*.root); do
    for f in $(ls /hadoop/cms/store/user/phchang/metis/baby/${VERSION}/*/*.root); do
        echo $f
        DIRNAME=$(dirname $f)
        DIRNAME=$(dirname $DIRNAME)
        SAMPLENAME=$(basename $DIRNAME)
        SAMPLENAME=${SAMPLENAME/_MINIAODSIM_${VERSION}/}
        FILENAME=$(basename $f)
        echo $SAMPLENAME
        echo './doAnalysis '$f' '${OUTPUTDIR}'/'${SAMPLENAME}${FILENAME}' -1 > '${OUTPUTDIR}'/'${SAMPLENAME}${FILENAME}'.log 2>&1' >> .jobs.txt
    done
fi

sh xargs.sh .jobs.txt
