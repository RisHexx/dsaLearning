#include <bits/stdc++.h>
using namespace std;
#define ll long long

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2 , 0);
        int i = 0;
        int j = nums.size() - 1;
        // first
        while(i < j){
            int mid = (i + j) / 2;
            if(nums[mid] == target && nums[mid - 1] != target){
                result[0] = i;
                break;
            }else if(nums[mid] < target){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }

        // second
        i = 0;
        j = nums.size() - 1;
        while(i < j){
            int mid = (i + j) / 2;
            if(nums[mid] == target && nums[mid + 1] != target){
                result[1] = i;
                break;
            }else if(nums[mid] < target){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }


        return result;
    }

int main() {
    std::ios_base::sync_with_stdio(false);
    vector<int>arr = {5,7,7,8,8,10};
    vector<int> result = searchRange(arr , 8);

    for(int i : result){
        cout<< i <<" ";
    }
    
    return 0;
}