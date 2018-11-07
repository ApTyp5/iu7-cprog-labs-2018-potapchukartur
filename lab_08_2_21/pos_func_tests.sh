#!/bin/bash

testdir=./pos_tests
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
        "$execute o $testdir/in_g2 $outfile"
        "$execute o $testdir/in_g3 $outfile"
        )

comment=(
        "Addition test 1"
        "Addition test 2"
        "Addition test 3"
        "Multiplication test 1"
        "Multiplication test 2"
        "Multiplication test 3"
        "Ghauss test 1"
        "Ghauss test 2"
        "Ghauss test 3"
        )

outfiles=(
         "out_a1"
         "out_a2"
         "out_a3"
         "out_m1"
         "out_m2"
         "out_m3"
         "out_g1"
         "out_g2"
         "out_g3"
         )


echo -e "\n###--> Positive function tests <--###\n"

for i in ${!outfiles[*]}
do
    ${comman[$i]} 2>/dev/null
    result=$?

    $diffcom $outfile $testdir/${outfiles[$i]}
    outcode=$?


    if (( $outcode == 0 ))
    then 
        verdict=SUCCESS
    else
        verdict=FAIL
    fi


    echo "--> ${comment[$i]}:"
    echo "command: '${comman[$i]}'"
    echo "recieved code: $result"
    echo "verdict: $verdict"
    echo -e "\n"

    if (( $outcode != 0 ))
    then
        exit -1
    fi
done
         

