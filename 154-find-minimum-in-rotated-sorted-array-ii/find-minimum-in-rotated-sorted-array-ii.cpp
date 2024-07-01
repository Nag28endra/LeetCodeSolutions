#include<bits/stdc++.h>

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res = INT_MAX;
        if(n==1) return nums[0];
        
        while(low<=high){
            __int128_t mid = (low + high)>>1;
            // if (nums[low]<nums[high]) return nums[low];
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                res = min(res, nums[low]);
                low++;
                high--;
                continue;
            }
            if (nums[low]<=nums[mid]){
                res = min(res,nums[low]);
                low = mid + 1;
            }
            else{
                res = min(res,nums[mid]);
                high = mid - 1;
            }
        }
        return res;
    }
};