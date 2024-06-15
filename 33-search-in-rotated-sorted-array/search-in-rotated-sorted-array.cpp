class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size();
        int low = 0;
        int high = n - 1;

        while(low<=high){

            int mid = low + (high-low)/2;

            if (nums[mid]==target)return mid;

            //go to left sorted array if exists
            if (nums[low]<=nums[mid]){
                    if (nums[low]<=target && target<=nums[mid]){
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
            }
            // go to right sorted array if exists;
            else{
                if (nums[mid]<=target && target<=nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};