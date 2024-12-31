class Solution {
public:
    int getCount(vector<int> &nums, int k){
        int l=0,r=0;
        int count=0;
        // create a map to track the nums values and their frequency
        unordered_map<int,int> mpp;

        while(r<nums.size()){
            mpp[nums[r]]++;

            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }

            count += (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return getCount(nums,k) - getCount(nums,k-1);
    }
};