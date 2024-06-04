class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xrr = 0;

        for(int i = 0; i<nums.size(); i++){
            xrr ^= nums[i];
        }
        return xrr;
    }
};