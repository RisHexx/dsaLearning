#include <bits/stdc++.h>
using namespace std;
#define ll long long
// check array is sorted

bool sorted(int arr[] , int size){
    if(size <= 1) return true;
    if(arr[0] > arr[1]) {
        return false;
    }
    return sorted(arr + 1 , size - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int size;
    cin>>size;
    int arr[size] = {};
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }

    cout<<sorted(arr , size);
    
    return 0;
}