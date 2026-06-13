#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr = {6,3,7,8,2,5};
    int n = arr.size();

    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >=0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for(int i : arr){
        cout<< i<<" ";
    }
    return 0;
}