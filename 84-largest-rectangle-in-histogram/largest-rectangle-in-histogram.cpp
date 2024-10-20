class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // stack to store values related pse.
        stack<int> st;
        int maxi = INT_MIN;

        for(int i = 0; i<heights.size(); i++){
            // check if the  current value is greater than the value on the top of the stack.
            while(!st.empty() && heights[st.top()] > heights[i]){
                // store the index of top of the stack.
                int element_idx = st.top();
                st.pop();
                // nse will be the current value's index.
                int nse = i;
                // pse will be either -1 or index on the top of the stack.
                int pse = st.empty()?-1: st.top();
                maxi = max(maxi, heights[element_idx]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int element_idx = st.top();
            st.pop();
            int nse = heights.size();
            int pse = st.empty()?-1:st.top();
            maxi = max(maxi,heights[element_idx]*(nse-pse-1));
        }
        return maxi;
    }
};