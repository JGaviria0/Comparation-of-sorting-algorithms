#include <iostream>
using namespace std;

long long comparation = 0; 
long long swaps = 0; 
long long iteration = 0;

void heapify(int arr[], int N, int i)
{

	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest]){
		largest = l;
		comparation++;
	}

	// If right child is larger than largest
	// so far
	if (r < N && arr[r] > arr[largest]){
		largest = r;
		comparation++;
	}

	// If largest is not root
	if (largest != i) {
		comparation++;
		swaps++;
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// One by one extract an element
	// from heap
	for (int i = N - 1; i > 0; i--) {

		// Move current root to end
		swap(arr[0], arr[i]);
		swaps++;

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

int main () {

    int n; 
    int a[1000006];

    cin >> n; 

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    heapSort( a, n);

	cout << comparation << ";" << swaps << ";";


}
