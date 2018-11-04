#!/bin/bash

testdir=./tests
execute=./app.exe
outfile=./out
diffcom=./doubdiff.exe


comman=(
        "$execute a $testdir/in_a11 $testdir/in_a12 $outfile" 
        "$execute a $testdir/in_a21 $testdir/in_a22 $outfile" 
        "$execute a $testdir/in_a31 $testdir/in_a32 $outfile" 
        "$execute m $testdir/in_m11 $testdir/in_m12 $outfile" 
        "$execute m $testdir/in_m21 $testdir/in_m22 $outfile" 
        "$execute m $testdir/in_m31 $testdir/in_m32 $outfile" 
        "$execute o $testdir/in_g1 $outfile"
        )

comment=(
        "Addition       test 1"
        "Addition       test 2"
        "Addition       test 3"
        "Multiplication test 1"
        "Multiplication test 2"
        "Multiplication test 3"
        "Ghauss         test 1"
        )

outfiles=(
         "out_a1"
         "out_a2"
         "out_a3"
         "out_m1"
         "out_m2"
         "out_m3"
         "out_g1"
         )


echo -e "Positive function tests:\n"

for i in ${!comman[*]}
do
    ${comman[$i]}
    result=$?

    $diffcom $outfile ${outfiles[$i]}
    outcode=$?


    if (( $outcode == 0 ))
    then 
        verdict=SUCCESS
    else
        verdict=FAIL
    fi


    echo "${comment[$i]}:"
    echo "command: '${comman[$i]}'"
    echo "recieved code: $result"
    echo "verdict: $verdict"
    echo -e "\n"

    exit 1

done
         

