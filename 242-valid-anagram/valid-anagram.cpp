class Solution {
public:
    bool isAnagram(string s, string t) {
        int sN = s.size();
        int tN = t.size();

        if(sN != tN) return false;
        unordered_map<char,int> mpp;
        for(int i = 0; i<sN; i++){
            mpp[s[i]]++;
        }
        for(int i = 0; i<tN; i++){
            if(mpp.find(t[i]) == mpp.end() || mpp[t[i]] == 0) return false;
            mpp[t[i]]--;
        }
        return true;
    }
};