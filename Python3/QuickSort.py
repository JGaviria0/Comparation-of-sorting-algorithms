import sys

sys.setrecursionlimit(15000)
def partition(array, low, high):
    pivot = array[high]
 
    i = low - 1

    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            (array[i], array[j]) = (array[j], array[i])
 
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1
 
 
def quickSort(array, low, high):
    if low < high:
        pi = partition(array, low, high)
        quickSort(array, low, pi - 1)
        quickSort(array, pi + 1, high)


def main():

    n = int(input())
    a = list(map(int, sys.stdin.readline().strip().split()))

    quickSort(a, 0, n-1)

main()