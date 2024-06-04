class Solution {
public:
    vector<int> printRow(int n){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(ans);
        for(int i = 1; i<n; i++){
            ans *=(n-i);
            ans /= i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for( int row = 1; row<=numRows; row++){
            ans.push_back(printRow(row));
        }
        return ans;
    }
};
