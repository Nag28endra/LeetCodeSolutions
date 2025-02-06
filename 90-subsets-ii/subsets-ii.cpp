class Solution {
public:
    void findSubsets(int idx, vector<int> nums, vector<vector<int>> &ans, vector<int>& subset){
            // initially add the subset to the answer
            ans.push_back(subset);
            // iterate the nums array
            for(int i = idx; i<nums.size(); i++){
                // check if the next value is same or not
                if (i!= idx && nums[i] == nums[i-1]) continue;
                // add the value to the subset
                subset.push_back(nums[i]);
                // add the value to the subset
                findSubsets(i+1,nums,ans,subset);
                // remove the added value
                subset.pop_back();
            }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort the array
        sort(nums.begin(),nums.end());
        // define a data structure that stores our answer
        vector<vector<int>> ans;
        // define a data structure that stores the values in the subset
        vector<int> ds;
        findSubsets(0,nums,ans,ds);
        return ans;
    }
};