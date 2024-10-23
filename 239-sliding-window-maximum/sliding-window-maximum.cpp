class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        for(int i = 0;i<nums.size(); i++)
        {
            // check if the size of the window is increased or not. 
            if(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            // we use monotonic stack property, we store elements in decreasing order. We check this using while loop.
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            // push the current element index value.
            dq.push_back(i);
            // if the size of the window is k then store the maximum value in the window.
            if(i>=k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};