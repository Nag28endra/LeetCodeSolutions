class Solution {
public:
    int binarySearch(vector<int> &arr, int low, int high, int target){
        if(low>high)return -1;

        int mid = low + (high-low)/2;

        if (arr[mid]==target)return mid;
        else if(target>arr[mid]) return binarySearch(arr,mid+1,high,target);
        else return binarySearch(arr,low,mid-1,target);
    }
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};