#!/bin/bash

testdir=./neg_tests
execute=./app.exe

comman=("$execute 123" 
         "$execute h 123 123 123"
         "$execute q $testdir/in_a11 $testdir/in_a12 out"
         "$execute a $testdir/in_g3 out"
         "$execute m $testdir/in_g3 out"
         "$execute o $testdir/in_a11 $testdir/in_a12 out"
         "$execute a $testdir/in_a11 $testdir/in_a12 out"
         "$execute m $testdir/in_m11 $testdir/in_m12 out"
         "$execute o $testdir/in_g1 out"
         "$execute o $testdir/in_g2 out"
         "$execute o $testdir/in_g3 out"
         "$execute o $testdir/in_g4 out"
         "$execute o $testdir/in_any1 out"
         "$execute o $testdir/in_any2 out"
         "$execute o $testdir/in_any3 out"
         "$execute o $testdir/in_any4 out"
         "$execute o $testdir/in_any5 out"
         "$execute o $testdir/in_any6 out"
         "$execute a $testdir/in_any7 $testdir/in_any7 out"

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
         

