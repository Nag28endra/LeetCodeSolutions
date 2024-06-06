class Solution {
public:
    void merge(vector<int> &arr, long long low, long long mid, long long high){
        long long left = low;
        long long right = mid + 1;
        
        vector<int> temp;

        while(left<=mid && right<= high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(arr[left++]);

        }
        while(right<=high){
            temp.push_back(arr[right++]);
        }

        for(int i = low; i<=high; i++)
            arr[i] = temp[i-low];
    }
public:
    int countPairs(vector<int> &arr, long long low, long long mid, long long high){
        long long cnt=0;
        long long right = mid+1;

        for(int i = low; i<=mid; i++){
            while(right<=high && arr[i]>(long long)2*arr[right])right++;

            cnt += (right- (mid+1));
        }
        return cnt;
    }
public:
    int mergeSort(vector<int> &nums, long long  low, long long high){
        long long cnt = 0;

        if (low>=high)return cnt;

        long long mid = (low+high)/2;
        cnt +=mergeSort(nums,low,mid);
        cnt += mergeSort(nums,mid+1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};