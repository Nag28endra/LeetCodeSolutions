class Solution {
public:
    int findLargestRectangleHistogram(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element_idx = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxi = max(maxi, heights[element_idx]*(nse-pse-1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element_idx = st.top();
                st.pop();
                int nse = heights.size();
                int pse = st.empty()?-1:st.top();
                maxi = max(maxi, heights[element_idx]*(nse-pse-1));
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        // if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> prefixSum(cols, 0);
        int maxi = 0;

        // Build prefix sum (heights) for each row
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Calculate the height of consecutive 1's for each column
                prefixSum[col] = (matrix[row][col] == '1') ? prefixSum[col] + 1 : 0;
            }
            // Find the largest rectangle area for the current row of heights
            maxi = max(maxi, findLargestRectangleHistogram(prefixSum));
        }

        return maxi;
    }
};
