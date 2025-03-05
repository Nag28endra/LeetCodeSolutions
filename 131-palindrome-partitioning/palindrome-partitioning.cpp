class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        Partition(0,s,res,path);
        return res;
    }
    void Partition(int idx, string s, vector<vector<string>> &res, vector<string> &path){
        // the base case is when the string reaches the end, add it to the result
        if (idx == s.size()){
            res.push_back(path);
            return;
        }

        for (int i = idx; i<s.size(); i++){
            // check if the substring is valid palindrome or not
            if (isPalindrome(s,idx,i)){
                // add it to the path
                path.push_back(s.substr(idx,i-idx+1));
                Partition(i+1, s, res, path);
                path.pop_back(); // remove the recently  inserted string for backtracking purpose.
            }
        }
    }
    bool isPalindrome(string s, int start, int end ){
        while(start<=end){
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};