#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr = {6,3,8,2,5};
    int n = arr.size();
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - 1 - i ; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j] , arr[j + 1]);
            }
        }
    }   
    for(int i : arr){
        cout<< i<<" ";
    }
    
    return 0;
}