class Solution {
public:
    int findSplits(vector<int> nums, int split, int k){
        int n = nums.size();
        int cntSplits = 1;
        long long partition = 0;

        for(int i = 0; i<n; i++){
            if(partition+nums[i]<=split){
                partition += nums[i];
            }
            else{
                cntSplits++;
                partition = nums[i];
            }
        }
        return cntSplits;
    }
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = low + (high-low)/2;

            int splits = findSplits(nums, mid, k);
            if(splits>k) low = mid + 1;
            else  high = mid - 1;
        }
        return low;
    }
    
};