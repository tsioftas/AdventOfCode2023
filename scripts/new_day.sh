
if [[ $1 != "" ]]
then
	DAY=$1
	mkdir Day${DAY}
	cp scripts/templates/d\$\$_1.cpp Day${DAY}/d${DAY}_1.cpp
	cp scripts/templates/d\$\$_2.cpp Day${DAY}/d${DAY}_2.cpp
	cp scripts/templates/d\$\$_common.cpp Day${DAY}/d${DAY}_common.cpp
	cp scripts/templates/d\$\$_common.h Day${DAY}/d${DAY}_common.h
	touch Day${DAY}/d${DAY}.in
else
	echo "Provide 1 argument, the number of the new day"
fi
