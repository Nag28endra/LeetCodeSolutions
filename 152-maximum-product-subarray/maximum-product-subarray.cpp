class Solution {
public:
    int maxProduct(vector<int>& nums) {
        __int128_t prefix=1;
        __int128_t suffix = 1;
        __int128_t  maxi = INT_MIN;

       for(int i = 0; i<nums.size(); i++){
        if(prefix==0)prefix = 1;
        if(suffix==0)suffix =1;

        prefix *= nums[i];
        suffix *= nums[nums.size()-i-1];

        maxi = max(maxi, max(prefix,suffix));
       } 
       return maxi;
    }
};