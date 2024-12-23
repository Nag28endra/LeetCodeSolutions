class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxlen=0;
        unordered_map<int,int> mpp;

        while(r<fruits.size()){
            mpp[fruits[r]]++;
            // if the size of the basket is greater than 2.
            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size() <= 2){
                maxlen = max(r-l+1,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};