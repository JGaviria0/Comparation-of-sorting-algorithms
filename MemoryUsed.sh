#!/bin/bash

echo "Datos;TreeSort;HeapSort;MergeSort;QuickSort;Introsort;TimSort"
for VARIABLE in 10 20 40 80 160 320 640 1280 2560 5120 10240 20480 40960 81920 163840 327680 655360
do
    # Data Generator
    echo "$VARIABLE" > in
    g++ DataGenerator.cpp 
    ./a.out < in > input

    echo -n "$VARIABLE;"

    for algorithm in HeapSort #TreeSort HeapSort MergeSort QuickSort Introsort TimSort
    do

        $(python3 Python3/$algorithm.py < input)
        
    done
    echo ""
done