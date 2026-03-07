#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr1 = {4,7,9,11};
    vector<int>arr2 = {5,8,10};
    vector<int>result;

    int i =0 ;
    int j = 0;  
    
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            result.push_back(arr1[i]);
            i++;
        }else{
            result.push_back(arr2[j]);
            j++;
        }
    }

    if(i < arr1.size()){
        while(i < arr1.size()){
            result.push_back(arr1[i]);
            i++;
        }
    }
    if(j < arr2.size()){
        while(j < arr2.size()){
            result.push_back(arr2[j]);
            j++;
        }
    }

    for(int k = 0 ; k < result.size() ; k++){
        cout<<result[k]<<" ";
    }
    return 0;
}