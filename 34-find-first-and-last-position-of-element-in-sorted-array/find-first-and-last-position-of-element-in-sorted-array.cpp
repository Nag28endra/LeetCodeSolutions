class Solution {
public: 
int findLast(vector<int>& arr, int n, int x){
    int low = 0;
    int high = n - 1;
    int last = -1;

    while(low<=high){
        int mid = low +(high-low)/2;

        if (arr[mid]==x){
            last = mid;
            low = mid +1;
        }
        else if(arr[mid]<x)low = mid +1;
        else high = mid - 1;
    }
    return last;
}
public:
    int findFirst(vector<int> &arr, int n, int x){
        int low = 0;
        int high = n-1;
        int first = -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if (arr[mid]==x){
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid]>x) high = mid - 1;
            else low =  mid + 1;
        }
        return first;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums,nums.size(),target);
        if (first ==  -1)return {-1,-1};
        int last = findLast(nums,nums.size(),target);

        return {first, last};
    }
};