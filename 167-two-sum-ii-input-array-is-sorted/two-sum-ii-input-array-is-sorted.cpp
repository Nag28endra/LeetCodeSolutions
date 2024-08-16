class Solution {
public:
    int check(vector<int> &numbers, int low, int high, int target){
        while(low<=high){
            int mid = low + (high-low)/2;

            if(numbers[mid]==target) return mid;
            else if (numbers[mid]<target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i =0; i<numbers.size(); i++){
            int rem = target - numbers[i];
            int index = check(numbers, i+1,numbers.size()-1,rem);

            if(index !=-1){
                return {i+1,index+1};
            }
        }
        return {-1,-1};
    }
};