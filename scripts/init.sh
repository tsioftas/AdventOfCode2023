DAY=$1
DIR="../Day$DAY"
SOURCEFILE="$DIR/d${DAY}.cpp"
EXECUTABLE="$DIR/d${DAY}.tsk"

if [[  $2 == "-g" ]] || [[ $3 == "-g" ]] || [[ $4 == "-g" ]]
then
    DEBUG="-g"
fi

if [[ $3 == "-o" ]] || [[ $2 == "-o" ]]  || [[ $4 == "-o" ]]
then
    OUTFILE="$DIR/d${DAY}.out"
else
    OUTFILE=""
fi


if [[ $3 == "-i" ]] || [[ $2 == "-i" ]]  || [[ $4 == "-i" ]]
then
    INFILE="$DIR/d${DAY}.in"
else
    INFILE=""
fi
