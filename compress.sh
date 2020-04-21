#!/bin/bash

read -p "Assignment #: " asn

echo "Compressing sources..."

compdir="./solutions"
if [ ! -d $compdir ]; then
    mkdir $compdir
fi

zip -r "./solutions/Assignment${asn}.zip" "./lib/asn_${asn}"

echo "Compression finished."
