class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, zeros = 0, maxLen = 0;

        while( r < nums.size()){
            if(nums[r] == 0)zeros++;
            if(zeros>k){
                if(nums[l] == 0)zeros--;
                l++;
            }
            if(zeros<=k){
                int len = r - l + 1;
                maxLen = max(len,maxLen);
            }
            r++;
        }
        return maxLen;
    }
};