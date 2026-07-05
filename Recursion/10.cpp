// element present in array or not
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int arr[] , int size , int x){
    if(size == 0) return false;
    if(arr[0] == x){
        return true;
    }
    return check(arr + 1 , size - 1 , x);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int size;
    cin>>size;
    int arr[size];
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    cout<<check(arr , size , 6);
    
    return 0;
}