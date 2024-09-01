class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // length(1D) == mxn then it is possible.
        if(m*n != original.size()) return {};

        vector<vector<int>> twoDArray(m, vector<int>(n));

        for(int i = 0; i<(m*n); i++){
            twoDArray[i/n][i%n] = original[i];
        }
        return twoDArray;
    }
};