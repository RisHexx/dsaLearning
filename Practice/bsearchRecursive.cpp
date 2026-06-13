#include <bits/stdc++.h>
using namespace std;
#define ll long long

int bSearch(vector<int> & arr , int low , int high, int k){
    if(low > high) return -1;

    int mid = (low + high) / 2;
    if(arr[mid] == k){
        return mid;
    }else if(arr[mid] < k){
        return bSearch(arr,mid + 1 , high , k);
    }else{
        return bSearch(arr,low , mid - 1 , k);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int> arr = {1,4,7,12,14,18,21,24};
    cout<< bSearch(arr , 0 , 7 , 21);
    
    return 0;
}