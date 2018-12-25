#!/bin/bash

VERSION=$1
VERSION=HWW2016_v2.0.0
OUTPUTDIR=outputs/${VERSION}
mkdir -p ${OUTPUTDIR}

rm .jobs.txt
for f in $(ls /hadoop/cms/store/user/phchang/metis/baby/${VERSION}/*/*.root); do
    echo $f
    DIRNAME=$(dirname $f)
    SAMPLENAME=$(basename $DIRNAME)
    SAMPLENAME=${SAMPLENAME/_MINIAODSIM_${VERSION}/}
    FILENAME=$(basename $f)
    echo $SAMPLENAME
    echo './doAnalysis '$f' '${OUTPUTDIR}'/'${SAMPLENAME}${FILENAME}' -1 > '${OUTPUTDIR}'/'${SAMPLENAME}${FILENAME}'.log 2>&1' >> .jobs.txt
done

#sh rooutil/xargs.sh .jobs.txt
