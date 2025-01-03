class Solution {
public:
    void Swap(vector<char> &s, int l, int r){
        char temp = s[l];
        s[l] = s[r];
        s[r] = temp;
    }
    void reverseString(vector<char>& s) {
        int l=0;
        int r=s.size() - 1;

        while(l<r){
            Swap(s,l,r);
            l++;
            r--;
        }
    }
};