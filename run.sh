#!/bin/bash

for VARIABLE in 10 100 1000 #10000 700000
do
    # Data Generator
    echo "\n\nWith $VARIABLE data: "
    echo "$VARIABLE" > in
    g++ DataGenerator.cpp 
    ./a.out < in > input

    for algorithm in MergeSort QuickSort Introsort
    do

        echo "Sorting altgorithm: $algorithm"
        $(g++ C++/$algorithm.cpp)
        totaltime=0;
        echo "c++ script"
        for i in $(seq 1 10)
        do
            start=`date +%s.%N`
            ./a.out < input
            end=`date +%s.%N`
            runtime=$( echo "$end - $start" | bc -l )
            totaltime=$( echo "$totaltime + $runtime" | bc -l )

        done

        runtime=$( echo "$totaltime / 10" | bc -l )
        echo "0$runtime"

        # Run Python3 Script
        totaltime=0;
        echo "Pyhton3 script"
        for i in $(seq 1 10)
        do
            start=`date +%s.%N`
            $(python3 Python3/$algorithm.py < input)
            end=`date +%s.%N`
            runtime=$( echo "$end - $start" | bc -l )
            totaltime=$( echo "$totaltime + $runtime" | bc -l )

        done

        runtime=$( echo "$totaltime / 10" | bc -l )
        echo "0$runtime"
    done
done