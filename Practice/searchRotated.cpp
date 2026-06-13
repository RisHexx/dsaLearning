#include <bits/stdc++.h>
using namespace std;
#define ll long long


 int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            int mid = (i + j) / 2;
            if(target == nums[mid]) return mid;
            else if(nums[mid] > nums[j]){
                if(target < nums[mid] && target >= nums[i]){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            }else if(nums[mid] < nums[j]){
                if(target > nums[mid] && nums[mid] < nums[i] && target >= nums[i]){
                    j = mid - 1;
                }else if(target < nums[mid]){
                    j = mid - 1;
                }else{
                    i = mid + 1;
                }
            }
        }
        if(nums[i] == target) return i;

        return -1;
    }

int main() {
    std::ios_base::sync_with_stdio(false);
    // vector<int> arr = {4,5,6,7,0,1,2};
    vector<int> arr = {1,3};
    cout<< search(arr , 3);
    
    return 0;
}