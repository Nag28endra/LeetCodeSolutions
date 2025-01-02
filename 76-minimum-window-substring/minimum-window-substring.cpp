class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0;
        int minLen = INT_MAX;
        int count=0, startIdx = -1;
        int sSize = s.size(), tSize = t.size();
        unordered_map<char,int> mpp;
        // pre insert t characters into the hash map
        for(int i =0; i<tSize; i++) mpp[t[i]]++;

        while(r<sSize){
            // check if the character is there in the map or not.
            if(mpp[s[r]] > 0) count++;
            mpp[s[r]]--;

            // if the size of count reaches the size of the t string
            while(count == tSize){
                if (r-l+1 < minLen){
                    minLen = r-l+1;
                    startIdx = l;
                }
                mpp[s[l]]++;
                if (mpp[s[l]] > 0) count -=1;
                l++;
            }
            r++;
        }
        return startIdx == -1 ? "" : s.substr(startIdx,minLen);
    }
};