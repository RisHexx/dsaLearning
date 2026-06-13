#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    int *p = new int;     // uninitialized (garbage)
    int *q = new int(42); // initialized to 42

    // Allocating an array

    int *arr1 = new int[5];                // uninitialized
    int *arr2 = new int[5]{};              // zero initialized
    int *arr3 = new int[5]{1, 2, 3, 4, 5}; // initialized with values

    // new throws an exception on failure
    try{
        p = new int[999999999];
    }
    catch (std::bad_alloc &e){
        cout << "failed: " << e.what();
    }

    int rows = 3;
    int cols = 3;
    // array of type int*
    int** arr = new int*[rows];

    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];  // each row is its own contiguous block
    }

    delete p;
    delete q;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr;

    return 0;
}