class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,-1);
        int l=0,r=0;
        int maxLen = INT_MIN;
        int len;

        if (s.size() == 0) return 0;
        while(r<s.size()){
            if(mpp[s[r]] != -1){
                if(mpp[s[r]] >= l){
                    l = max(mpp[s[r]] + 1,l);
                }
            }
            len = r - l + 1;
            maxLen= max(len,maxLen);
            mpp[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};