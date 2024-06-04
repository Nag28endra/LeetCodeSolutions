class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n =nums.size();
        int cnt = 0, element;
        for(int i = 0; i<n; i++){
                if(cnt == 0){
                    cnt = 1;
                    element = nums[i];
                }
                else if (nums[i]==element)cnt++;
                else cnt--;
        }
        int counter = 0;
        for(int i = 0; i<n ;i++){
            if(nums[i]==element)counter++;
        }
        if (counter> (n/2))return element;
        else return -1;
    }
};