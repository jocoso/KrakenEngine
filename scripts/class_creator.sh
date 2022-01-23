#!/bin/bash

CLASSNAME=$1
ADDRESS=$2

./source_creator.sh $CLASSNAME $ADDRESS && ./header_creator.sh $CLASSNAME $ADDRESS