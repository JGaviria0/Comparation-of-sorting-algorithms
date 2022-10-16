#include <bits/stdc++.h>

using namespace std; 

long long comparation = 0; 
long long swaps = 0; 
long long iteration = 0;

void swap(int arr[] , int pos1, int pos2){
	int temp;
	swaps++; 
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot){
	int i = low;
	int j = low;
	while( i <= high){
		comparation++;
		if(arr[i] > pivot){
			i++;
		}
		else{
			swap(arr,i,j);
			i++;
			j++;
		}
	}
	return j-1;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		comparation++; 
	int pivot = arr[high];
	int pos = partition(arr, low, high, pivot);
	
	quickSort(arr, low, pos-1);
	quickSort(arr, pos+1, high);
	}
}

int main () {

    int n; 
    int a[1000006];

    cin >> n; 

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    quickSort( a, 0, n-1);
	cout << comparation << ";" << swaps << ";";
	// cout << "Comparation: " << comparation << endl ;
	// cout << "Swaps: " << swaps << endl; 

}