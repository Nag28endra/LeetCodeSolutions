class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxFreq=0;
        unordered_map<char,int> mpp;
        // allocating space for map
        mpp.reserve(26);

        while(r<s.size()){
            // increase the frequency of the character in the map
            mpp[s[r]-'A']++;
            // get the maximum frequency from the map
            maxFreq = max(maxFreq,mpp[s[r]-'A']);
            // check if the changes are exceed the k.
            // length of current string - maxFrequency in the map
            if( (r-l+1) - maxFreq > k){
                mpp[s[l]-'A']--;
                l++;
            }
            if( (r-l+1) - maxFreq <= k){
                maxlen = max(maxlen,r-l+1);
            }
           r++;
        }
        return maxlen;
    }
};