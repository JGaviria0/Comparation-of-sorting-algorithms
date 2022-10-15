#!/bin/bash

echo "Datos;TreeSort;HeapSort;MergeSort;QuickSort;Introsort;TimSort"
for VARIABLE in 10 20 40 80 160 320 640 1280 2560 5120 10240 20480 40960 81920 163840 327680 655360
do
    # Data Generator
    echo "$VARIABLE" > in
    g++ DataGenerator.cpp 
    ./a.out < in > input

    echo -n "$VARIABLE;"

    for algorithm in TreeSort HeapSort MergeSort QuickSort Introsort TimSort
    do

        # echo -n "Sorting altgorithm: $algorithm;"
        $(g++ C++/$algorithm.cpp)
        totaltime=0;
        # echo "c++ script"
        for i in $(seq 1 10)
        do
            start=`date +%s.%N`
            ./a.out < input
            end=`date +%s.%N`
            runtime=$( echo "$end - $start" | bc -l )
            totaltime=$( echo "$totaltime + $runtime" | bc -l )

        done

        runtime=$( echo "$totaltime / 10" | bc -l )
        echo -n "0$runtime;"

        # Run Python3 Script
        totaltime=0;
        # echo "Pyhton3 script"
        for i in $(seq 1 10)
        do
            start=`date +%s.%N`
            $(python3 Python3/$algorithm.py < input)
            end=`date +%s.%N`
            runtime=$( echo "$end - $start" | bc -l )
            totaltime=$( echo "$totaltime + $runtime" | bc -l )

        done

        runtime=$( echo "$totaltime / 10" | bc -l )
        echo -n "0$runtime;"
    done
    echo ""
done