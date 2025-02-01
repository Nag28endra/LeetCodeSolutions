class Solution {
public:
    void findCombinations(int idx, vector<int> candidate, int target, vector<vector<int>> &ans,vector<int> &combinations){
        // check if the index is equals to the size of the candiates arrays
        if(idx == candidate.size()){
            // check if the target has become zero or not
            if(target == 0){
                // add the combinations to your answer
                ans.push_back(combinations);
            }
            return;
        }

        // check if the value of the candidate is with in the target
        if (candidate[idx] <= target){
            // then pick the value fom the candidate
            combinations.push_back(candidate[idx]);
            // make call to the function to pick the same value
            findCombinations(idx,candidate,target-candidate[idx],ans,combinations);
            // remove the value of the candidate while backtracking to make sure it is not repeated
            combinations.pop_back();
        }
        // don't pick the value skip it, for that you need to make a function call
        findCombinations(idx+1,candidate,target,ans,combinations);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // define a data structure to return the answer
        vector<vector<int>> ans;
        // define a data structure to store the combinations
        vector<int> combinations;

        findCombinations(0,candidates, target, ans, combinations);
        return ans;
    }
};