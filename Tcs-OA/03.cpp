#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    int size;
    cin>>size;
    vector<int> arr(size);
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    // kadane Algorithm
    int currSum = arr[0];
    int maxSum = currSum;
    for(int i = 1 ; i < size ; i++){
        currSum = max(arr[i] , currSum + arr[i]);
        maxSum = max(maxSum , currSum);
    }
    cout<<maxSum;
    
    return 0;
}