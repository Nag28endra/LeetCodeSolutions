class Solution {
public:
    void printS(vector<int> nums, vector<vector<int>>& res, int n, int idx,vector<int>& subset){
        if (idx == n){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[idx]);
        printS(nums,res,n,idx+1,subset);
        subset.pop_back();
        printS(nums,res,n,idx+1,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> res;
       vector<int> subset;
       printS(nums,res,nums.size(),0,subset);
       return res;
    }
};