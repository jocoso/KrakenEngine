#!/bin/bash

CLASSNAME=$1
ADDRESS=$2

if test -z "$ADDRESS"
    then
        DIRECTION="$CLASSNAME.cpp"
    else
        DIRECTION="$ADDRESS\\$CLASSNAME.cpp"    
fi

echo "
    #ifndef _$CLASSNAME _
    #define _$CLASSNAME _
    class $CLASSNAME {
        $CLASSNAME::$CLASSNAME() {}
        $CLASSNAME::~$CLASSNAME() {}
    };
    #endif

" >> "$DIRECTION"