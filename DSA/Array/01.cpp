#include <bits/stdc++.h>
using namespace std;
#define ll long long

void insert(int pos , int data , vector<int>&arr){
    int index = pos - 1;
    arr.resize(arr.size() + 1);
    for(int i = arr.size() ; i > index ; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = data;
}

void deleteAtIndex(int idx, vector<int>&arr){
    for(int i = idx ; i < arr.size() ; i++ ){
        arr[i] = arr[i+1];
    }
    arr.pop_back();
}

int search(int data , vector<int>&arr){
    for(int i = 0 ; i < arr.size() ; i++){
        if(data == arr[i]){
            return i;
        }
    }
    return -1;
}

int bsearch(int data , vector<int>&arr){
    int start = 0 ; 
    int end = arr.size()- 1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(data == arr[mid]){
            return mid;
        } 
        else if(data < arr[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return -1;
    
}

void reverse(vector<int>& arr){
    if(arr.size() == 1) return ;
    int i = 0 ;
    int j = arr.size() - 1;
    while(i < j){
        swap(arr[i] , arr[j]);
        i++;
        j--;
    }
    return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr = {2,4,1,5,7};
    vector<int>sortedarr = {5,7,11,16,17,21};
    // insert(3,91,arr);
    // deleteAtIndex(3,arr);
    // int pos = search(9,arr);
    // int pos = bsearch(21,sortedarr);
    // cout<<pos<<endl;
    reverse(sortedarr);
    for(int i = 0 ; i < sortedarr.size() ; i++){
        cout<<sortedarr[i]<<" ";
    }
    
    
    return 0;
}