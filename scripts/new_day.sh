
if [[ $1 != "" ]]
then
	DAY=$1
	mkdir Day${DAY}
	touch Day${DAY}/d${DAY}_1.cpp
	touch Day${DAY}/d${DAY}_2.cpp
	touch Day${DAY}/d${DAY}_common.cpp
	touch Day${DAY}/d${DAY}_common.h
	touch Day${DAY}/d${DAY}.in
else
	echo "Provide 1 argument, the number of the new day"
fi
