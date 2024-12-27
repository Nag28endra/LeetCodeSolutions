class Solution {
public:
    int getCount(vector<int>& nums, int goal){
        int n = nums.size();
         int l=0,r=0,count=0,Sum=0;
         if (goal < 0) return 0;
         while(r<n){
            // compute sum
            Sum += nums[r];

            //check if the sum exceeds greater goal and eliminate the left pointer
            while(Sum > goal){
                Sum -= nums[l];
                l++;
            }
            count += (r-l+1);
            r++;
         }
         return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
         return getCount(nums,goal) - getCount(nums,goal-1);
    }
};