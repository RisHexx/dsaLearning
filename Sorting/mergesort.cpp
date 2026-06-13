#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<int>&arr, int start, int end){
    int mid = (start + end) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int* first = new int[len1];
    int* second = new int[len2];
    // copy values

    // original array pointer
    int k = start;
    for(int i = 0 ; i < len1 ; i++){
        first[i] = arr[k++];
    }
    k = mid + 1;
    for(int i = 0 ; i < len1 ; i++){
        second[i] = arr[k++];
    }

    // merge 2 sorted Array
    int i = 0;
    int j = 0;
    k = start;
    while(i < len1 && j < len2){
        if(first[i] < second[j]){
            arr[k++] = first[i++];
        }else{
            arr[k++] = second[j++];
        }
    }

    while(i < len1){
        arr[k++] = first[i++];
    }
    while(j < len2){
        arr[k++] = second[j++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(vector<int>&arr, int start, int end){
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10 };
    mergeSort(arr, 0, arr.size() - 1);
    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}