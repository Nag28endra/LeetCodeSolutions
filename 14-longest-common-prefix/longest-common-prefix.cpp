class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        sort(strs.begin(),strs.end());
        int n = strs.size();

        string first = strs[0], last = strs[n-1];

        for(int i =0; i<min(first.size(), last.size()); i++){
            if(first[i] != last[i]) return res;
            res += first[i];
        }
        return res;
    }
};