#!/bin/bash

source init.sh

if [[ ! -d $DIR ]]
then
    echo "Creating directory $DIR"
    mkdir -p $DIR
fi

if [[ ! -e $SOURCEFILE ]]
then
    echo "Creating sourcefile $SOURCEFILE"
    cp template.cpp $SOURCEFILE
fi

COMPILATION_SUCCESS=0

if [[ $DEBUG == "-g" ]]
then
    echo "Compiling $SOURCEFILE with debug flags..."
    if g++ $SOURCEFILE -o $EXECUTABLE -g
    then
        COMPILATION_SUCCESS=1
    fi
else
    echo "Compiling $SOURCEFILE..."
    if g++ $SOURCEFILE -o $EXECUTABLE
    then
        COMPILATION_SUCCESS=1
    fi
fi

if [[ $COMPILATION_SUCCESS == 1 ]]
then
    echo "Running $SOURCEFILE..."

    if [[ $OUTFILE != "" ]] && [[ $INFILE != "" ]]
    then
        cat $INFILE | $EXECUTABLE > $OUTFILE
    elif [[ $INFILE != "" ]]
    then
        cat $INFILE | $EXECUTABLE
    elif [[ $OUTFILE != "" ]]
    then
        $EXECUTABLE > $OUTFILE
    else
        $EXECUTABLE
    fi
fi
