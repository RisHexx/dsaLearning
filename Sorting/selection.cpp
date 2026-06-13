#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int> arr = {4 , 2 , 3 , 5, 9};
    int n = arr.size();
    for(int i = 0 ; i < n - 1 ; i++){
        int minIndx = i;
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] < arr[minIndx] ){
                minIndx = j;
            }
        }
        swap(arr[i], arr[minIndx]);
    }
    
    for(int i : arr){
        cout<< i<<" ";
    }
    return 0;
}