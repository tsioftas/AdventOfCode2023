DAY=$1
PART=$2
DIR="../Day$DAY"
COMMON_SOURCEFILE="$DIR/d${DAY}_common.cpp"
SOURCEFILE="$DIR/d${DAY}_${PART}.cpp"
EXECUTABLE="$DIR/d${DAY}_${PART}.tsk"
WORKING_DIR=$(pwd)/$DIR

if [[  $3 == "-g" ]] || [[ $4 == "-g" ]] || [[ $5 == "-g" ]]
then
    DEBUG="-g"
fi

if [[ $4 == "-o" ]] || [[ $3 == "-o" ]]  || [[ $5 == "-o" ]]
then
    OUTFILE="$DIR/d${DAY}_${PART}.out"
else
    OUTFILE=""
fi


if [[ $4 == "-i" ]] || [[ $3 == "-i" ]]  || [[ $5 == "-i" ]]
then
    INFILE="$DIR/d${DAY}.in"
else
    INFILE=""
fi
