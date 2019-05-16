#!/bin/bash
DIR=client1
mkdir $DIR
cd $DIR
../bin/soapcpp2 -x -C -c -I ../gsoap/import/ -I ../gsoap/ ../onvif_head/onvif.h

cd -