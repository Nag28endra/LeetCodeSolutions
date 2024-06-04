class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int flag = 1;
        for (unsigned int i = 0; i<nums.size();i++){
            if (nums[i]==0){
                flag = 0;
                break;
            }
        }
        if (flag == 1)return;
        else{
        int j=-1;
        unsigned int size = nums.size();
        for (unsigned int i = 0; i<size ;i++){
            if (nums[i]==0){
                j = i;
                break;
            }
        }

        for (unsigned int i = j+1; i<size; i++){
            if ( nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        }
    }
};