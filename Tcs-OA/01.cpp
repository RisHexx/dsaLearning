#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i= 0 ; i < size ; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int count = 0;
    for(int i = 0 ; i < size ; i++){
        int sum = 0;
        for(int j = i ; j < size ; j++ ){
            sum += arr[j];
            if(sum == k){
                count++;
            }
        }
    }
    cout<<count;
    
    return 0;
}