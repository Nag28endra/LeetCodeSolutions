class Solution {
public:
    void findCombinations(int idx, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &combinations, int target){
        // check whether the target is zero or not
        if (target == 0){
            // add the combinations to the ans and return
            ans.push_back(combinations);
            return;
        }
        for(int i = idx; i<candidates.size(); i++){
            // check if the next element is same or not to avoid duplication
            if (i>idx && candidates[i] == candidates[i-1])continue;
            // if the value of the candidate is greater than the target then break it.
            if (candidates[i] > target) break;
            // add the value to the combinations.
            combinations.push_back(candidates[i]);
            // make a function call to check for next possibility
            findCombinations(i+1, candidates,ans,combinations,target-candidates[i]);
            // remove the element that is recently added to ensure the combination is not repeated.
            combinations.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // first we sort the array to ensure that the answer is in chronological order
        sort(candidates.begin(),candidates.end());
        // define a data structure to store our answer.
        vector<vector<int>> ans;
        // defiine a data structure to store my combinations
        vector<int> combinations;
        findCombinations(0,candidates,ans,combinations,target);
        return ans;
    }
};