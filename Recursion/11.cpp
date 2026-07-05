// first index
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int firstIndex(int arr[] , int size , int x){
    if(size == 0) return -1;
    if(arr[0] == x){
        return 0;
    }
    int ans = firstIndex(arr + 1 , size - 1 , x);
    if(ans == -1){
        return ans;
    }else{
        return ans + 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int size;
    cin>>size;
    int arr[size];
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    cout<<firstIndex(arr , size , 5);
    
    return 0;
}