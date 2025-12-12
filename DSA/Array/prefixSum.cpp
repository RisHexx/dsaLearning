#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr = {2,4,7,3,1};

    for(int i = 1 ; i < arr.size() ;i++){
        arr[i] += arr[i-1];
    }

    for(int i = 0 ; i < arr.size() ; i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}