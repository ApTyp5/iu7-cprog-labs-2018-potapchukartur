#!/bin/bash

testdir=./tests
execute=./app.exe

comman=("$execute 123" 
         "$execute q $testdir/in_11 $testdir/in_12 out"
         "$execute a $testdir/in_3 out"
         "$execute h 123 123 123"
         "$execute m $testdir/in_3 out"
         "$execute o $testdir/in_11 $testdir/in_12 out"
         )

for i in ${!comman[*]}
do
    ${comman[$i]}
    result=$?

    if (( result != 0 ))
    then
        verdict=SUCESS
    else
        verdict=FAIL
    fi

    echo "Neg test $i ended with code $result: $verdict"
done
         

