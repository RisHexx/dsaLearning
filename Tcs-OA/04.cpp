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

    // Logic to find unique elements in array after sorting 
    sort(arr.begin() , arr.end());
    int sum = 0;
    int i = 0;
    while( i < size ){
        int j = i + 1;
        while(j < size && arr[i] == arr[j]){
            j++;
        }
        if(j - i == 1){
            sum += arr[i];
        }
        i = j;
    }
    cout << sum;
    return 0;
}