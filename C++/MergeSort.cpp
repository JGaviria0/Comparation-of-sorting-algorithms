#include <bits/stdc++.h>

using namespace std; 

#define MAXT 4471
#define MAXS 10000000
#define inf 2147483647

long long comparation = 0; 
long long swaps = 0; 
long long iteration = 0;

void Merge(int A[], int p, int q, int r)
{
	int i, j, k , n1 = (q - p + 1), n2 = (r - q);
	int L[n1 + n2], R[n2 + 2];
	
	for(i=1;i<=n1;i++)
	   L[i]=A[p+i-1];
	
	for(j=1;j<=n2;j++)
	   R[j]=A[q+j];
	
	L[n1+1]=inf;
	R[n2+1]=inf;
	i=1;
	j=1;
	
	for(k=p;k<=r;k++)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
		   A[k] = R[j];
			j++;
		}
		comparation++; 
		swaps++;
	}  
}

void MergeSort(int A[], int p, int r)
{
	int q;
	if(p<r)
	{	
		comparation++; 
		q = (p+r)>>1;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}


int main () {

    int n; 
    int a[1000006];

    cin >> n; 

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    MergeSort( a, 0, n-1);

	cout << comparation << ";" << swaps << ";";
	 

}