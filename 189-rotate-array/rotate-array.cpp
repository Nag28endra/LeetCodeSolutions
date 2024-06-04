class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int size = nums.size();
         k %=size;
         if(size<k){
            
            reverse(nums.begin(),nums.end());
         }
         else{
         reverse(nums.begin(),nums.end());
         reverse(nums.begin(),nums.begin()+k);
         reverse(nums.begin()+k,nums.end());
         }
         }
    };
