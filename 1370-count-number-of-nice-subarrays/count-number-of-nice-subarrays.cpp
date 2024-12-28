class Solution {
public:
    // this is the algorithm used for the problem: Binary Sum subarray equals to K
    int getSubArrayCount(vector<int> &nums, int k){
        int r=0,l=0;
        int count = 0, Sum= 0;

        while(r<nums.size()){
            Sum += (nums[r]%2);

            while(Sum > k){
                Sum -= (nums[l]%2);
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return getSubArrayCount(nums,k) - getSubArrayCount(nums,k-1);
    }
};