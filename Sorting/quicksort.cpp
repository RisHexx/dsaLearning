#include <bits/stdc++.h>
using namespace std;
#define ll long long

int partition (vector<int> &arr , int start , int end){
    int pivot = arr[start];
    int i = start + 1;
    int j = end;

    while(true){
        while(i <= end && arr[i] <= pivot) i++;
        while(j >= start && arr[j] > pivot) j--;

        if(i < j){
            swap(arr[i] , arr[j]);
        }else{
            break;
        }
    }
    swap(arr[start] , arr[j]);
    return j;

}

void quickSort(vector<int> &arr , int start , int end){
    if(start >= end) return;

    int partitionIndex = partition(arr , start , end);

    quickSort(arr , start , partitionIndex - 1);
    quickSort(arr , partitionIndex + 1 , end);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10 , 11};
    quickSort(arr, 0, arr.size() - 1);
    for (int i : arr)
    {
        cout << i << " ";
    }
    
    return 0;
}