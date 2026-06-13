#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr = {6,3,8,2,5};
    int n = arr.size();
    for(int i = 0 ; i < n - 1 ; i++){

// if no swap happens means array is sorted no need to check just break loop;
        bool swapped = false;
        for(int j = 0 ; j < n - 1 - i ; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j] , arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }
    }   
    for(int i : arr){
        cout<< i<<" ";
    }
    
    return 0;
}