class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // create a sum variable 
        __int128_t sum =0;
        for(int i = 0; i<rolls.size();i++) sum += rolls[i];

        __int128_t totalSum = mean * (n + rolls.size());
        __int128_t remainingSum = totalSum - sum;

        if( remainingSum<n || remainingSum >6*n) return {};
        __int128_t distributedMean = remainingSum/n;
        __int128_t mod = remainingSum % n;
        vector<int> nElements(n,distributedMean);

        for(int i = 0; i<mod ; i++){
            nElements[i]++;
        }
        return nElements;
    }
};