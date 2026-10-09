#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr(6);
    int num;
    for(int i = 0 ; i < 6 ; i++){
        cin>>num;
        arr[i] = num;
    }
    int max1 = INT_MIN;
    int max2 = max1;
    
    for(int i : arr){
        if(i > max1){
            max2 = max1;
            max1 = i;
        }else if(i > max2 && i != max1){
            max2 = i;
        }
    }
    cout<<max2;
    
    return 0;
}