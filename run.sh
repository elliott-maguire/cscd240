#!/bin/bash

read -p "Assignment #: " asn
read -p "Problem #: " pn
read -p "Arguments: " args

echo "Running binary..."

./bin/asn_${asn}/p_${pn} ${args}
