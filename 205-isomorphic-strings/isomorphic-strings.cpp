class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> mpp1;
        unordered_map<char, char> mpp2;

        for (int i = 0; i < n; i++) {
            char chS = s[i];
            char chT = t[i];

            if ((mpp1.find(chS) != mpp1.end() && mpp1[chS] != chT) ||
                (mpp2.find(chT) != mpp2.end()&& mpp2[chT] != chS)) return false;

            mpp1[chS] = chT;
            mpp2[chT] = chS;
        }
        return true;
    }
};