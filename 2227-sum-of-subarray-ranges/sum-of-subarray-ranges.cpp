class Solution {
public:
// find the next smallest element for each value in the array
    vector<long long> findNSE(vector<int> arr){
    stack<long long> st;
    vector<long long> nse(arr.size());
    // traverse from the back
    for(int i = arr.size() - 1; i>=0; i--){
        // if stack is not empty and top value is greater than current pop out.
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        // set nse value to size of array is stack is empty or to top of the stack of the value.
        nse[i] = st.empty() ? arr.size() : st.top();
        // push the current value index 
        st.push(i);
    }
    return nse;
}
    // find the previous smaller element for each value in the array.
    vector<long long> findPSE(vector<int> arr){
        stack<long long> st;
        vector<long long> pse(arr.size());
        // normal traversal
        for(int i = 0; i<arr.size(); i++){
            // pop those values which are only greater than current value.
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            // set to -1 if stack is empty or to top of the value.
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    // find next greater element 
    vector<long long> findNGE(vector<int> arr){
        stack<long long> st;
        vector<long long> nge(arr.size());
        // traverse from the last.
        for(int i = arr.size() - 1; i>=0; i--){
            // pop out those values which are less than or equal to current value.
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();

            nge[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nge;
    }
    // find the previous greater element.
    vector<long long> findPGE(vector<int> arr){
        stack<long long> st;
        vector<long long> pge(arr.size());
        for(int i = 0; i<arr.size(); i++){
            // pop out those values which are less than the current value.
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();

            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }
    // find sum of subarray maximum
    long long sum_of_subarray_max(vector<int> nums){
        long long maxtotal = 0;
        // find nge and pge
        vector<long long> nge = findNGE(nums);
        vector<long long> pge = findPGE(nums);
        long long mod = 1e9 + 7;
        for(int i = 0; i<nums.size(); i++){
            // get the index of left most greater element of current value.
            long long left = i - pge[i];
            // get the index of right most greater element of current value.
            long long right = nge[i] - i;

            maxtotal = (maxtotal + (left*right*nums[i]));
        }
        return  maxtotal;
    }
    // find sum of subbarray minimum 
    long long sum_of_subarray_min(vector<int> nums){
        long long mintotal = 0;
        // find nse and pse.
        vector<long long> nse = findNSE(nums);
        vector<long long> pse = findPSE(nums);
        long long mod = 1e9 + 7;
        for(int i = 0; i<nums.size(); i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;

            mintotal = (mintotal + (left*right*nums[i]));
        }
        return  mintotal;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        // find sum of subarray minimum and maximum to compute sum of subarrays.
        return sum_of_subarray_max(nums) - sum_of_subarray_min(nums);
    }
};