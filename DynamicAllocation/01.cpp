#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    int* p = (int *)malloc(sizeof(int)); 
    // malloc returns a void pointer so we need to cast it according to type of variable we are storing and malloc returns nullptr (or NULL in C) if it can't allocate.
    // malloc returns the starting address of a contiguous block of bytes on the heap.
    *p = 14;
    cout<<*p << endl;

    int* arr = (int *)malloc(sizeof(int) * 5);
    // 5 size array


    //calloc — allocate + zero initialize
    // takes 2 arguments (sizeof Arr , size)
    int* newArr = (int *)calloc(5, sizeof(int));
    for(int i = 0 ; i < 3 ; i++){
        cout<<newArr[i];
        // cout<<*(newArr + i);
    }


    // realloc -> its use to extend or contract the size
    int* tempArr = (int*) malloc(10 * sizeof(int));

    // contract — shrink from 10 to 3
    int* temp = (int*) realloc(arr, 3 * sizeof(int));   

    //If realloc fails it returns nullptr — but your original block is still alive. By overwriting arr directly you just lost the pointer to it → memory leak.
    if(temp != nullptr){
        tempArr = temp;
    }

    // extend size to 3 -> 5
    temp = (int*) realloc(arr, 5 * sizeof(int));
    if(temp != nullptr){
        tempArr = temp;
    }

    // to deleting the memory
    free(p);
    free(arr);
    free(tempArr);
    return 0;
}