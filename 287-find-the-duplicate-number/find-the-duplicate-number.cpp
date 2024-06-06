class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int val = -1;
        for(int i = 0; i<nums.size(); i++){
            if (nums[i]==nums[i+1]){
                val = nums[i];
                break;
            }
        }
        return val;
    }
};