#!/bin/bash

mkdir fastjet/
cd fastjet/
curl -O http://fastjet.fr/repo/fastjet-3.3.2.tar.gz 
tar zxvf fastjet-3.3.2.tar.gz
cd fastjet-3.3.2/
./configure --prefix=$PWD/../fastjet-install
make || exit 1
make check || exit 1
make install || exit 1
cd ..

wget http://fastjet.hepforge.org/contrib/downloads/fjcontrib-1.041.tar.gz
tar xvzf fjcontrib-1.041.tar.gz
cd fjcontrib-1.041/
./configure --fastjet-config=$PWD/../fastjet-install/bin/fastjet-config --only=Nsubjettiness,RecursiveTools
make || exit 1
make check || exit 1
make install || exit 1
cd ..
cd ..
