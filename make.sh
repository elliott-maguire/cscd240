#!/bin/bash

read -p "Assignment #: " asn
read -p "Problem #: " pn

echo "Compiling sources..."

compdir="./bin/asn_${asn}"
if [ ! -d $compdir ]; then
    mkdir $compdir
fi

gcc -o "./bin/asn_${asn}/p_${pn}" "./lib/asn_${asn}/p_${pn}.c"

echo "Compilation finished."
