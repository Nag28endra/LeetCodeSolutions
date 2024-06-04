class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, top = 0;
        int right = col-1,bottom =row-1;
        vector<int> res;

        while(left<=right && top<=bottom){
            //go right
            for(int i=left; i<=right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;

            // go down
            for(int i=top; i<=bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            // go left
            if(top<=bottom){
                for(int i = right; i>=left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            //go top
            if(left<=right){
                for(int i = bottom; i>=top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};