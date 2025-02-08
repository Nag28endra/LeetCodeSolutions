class Solution {
public:
    void findPermutations(vector<int> nums,int mpp[],vector<vector<int>> &ans, vector<int> &permutations){
        // check if the size of the array is equals to our data structure.
        if (nums.size() == permutations.size()) {
            ans.push_back(permutations);
            return;
        }

        for(int i =0; i<nums.size(); i++){
                if(!mpp[i]){
                    mpp[i] = 1;
                    permutations.push_back(nums[i]);
                    findPermutations(nums,mpp, ans, permutations);
                    mpp[i] = 0;
                    permutations.pop_back();
                }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // define the answer
        vector<vector<int>> ans;
        // define a hash map to keep track of your values.
        int mpp[nums.size()];
        for(int i = 0; i<nums.size(); i++) mpp[i] = 0;
        // define a data structure to store the permutations
        vector<int> permutations;
        findPermutations(nums,mpp,ans,permutations);
        return ans;
    }
};