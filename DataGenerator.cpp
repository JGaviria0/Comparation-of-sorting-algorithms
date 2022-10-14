#include <bits/stdc++.h>

using namespace std; 

int main () {

    int n; 
    srand (time(NULL));

    cin >> n;

    cout << n << endl; 

    while(n--) {
        cout << rand() % 1000000 << " ";
    }

    cout << endl; 
}