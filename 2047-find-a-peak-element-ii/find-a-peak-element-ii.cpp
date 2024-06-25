class Solution {
public:
    int maxElement(vector<vector<int>> arr, int n , int m , int col){
        int index = -1;
        int maxVal = -1;

        for(int i = 0 ; i<n; i++){
            if (arr[i][col]>maxVal){
                index = i;
                maxVal = arr[i][col];
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while(low<=high){
            int mid = (low + high)>>1;
            int row = maxElement(mat,n,m,mid);
            int right = (mid + 1)<m ? mat[row][mid+1]:-1;
            int left = (mid - 1)>=0 ? mat[row][mid-1]:-1;

            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if (mat[row][mid]<left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1,-1};
    }
};