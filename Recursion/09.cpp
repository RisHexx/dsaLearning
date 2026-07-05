// sum of array
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sumarray(int arr[] , int size){
    if(size == 0) return 0;
    return arr[0] + sumarray(arr + 1 , size - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int size;
    cin>>size;
    int arr[size];
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    cout<<sumarray(arr , size);
    
    return 0;
}