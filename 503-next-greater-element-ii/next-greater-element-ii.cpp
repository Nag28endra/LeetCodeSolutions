class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N);
        stack<int> st;

        // traversing from the back.
        for(int i = 2*N-1; i>=0; i--){  

            while(!st.empty() && st.top() <= nums[i%N]) st.pop();

            if(i<N)result[i] = st.empty() ? -1 : st.top();
            st.push(nums[i%N]);
        }
        return result;
    }
};