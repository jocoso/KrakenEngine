#!/bin/bash

CLASSNAME=$1
ADDRESS=$2

if test -z "$ADDRESS"
    then
        DIRECTION="$CLASSNAME.h"
    else
        DIRECTION="$ADDRESS\\$CLASSNAME.h"    
fi

echo "
    #ifndef _$CLASSNAME _
    #define _$CLASSNAME _

    class $CLASSNAME {
        public:
            $CLASSNAME();
            ~$CLASSNAME();
    };

    #endif

" >> "$DIRECTION"