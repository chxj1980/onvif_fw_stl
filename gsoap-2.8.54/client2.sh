#!/bin/bash

DIR=client2
mkdir $DIR
cd $DIR

../bin/soapcpp2 -x -C -c++ -i -I ../gsoap/import/ -I ../gsoap/ ../onvif_head/onvif.h

cd -
