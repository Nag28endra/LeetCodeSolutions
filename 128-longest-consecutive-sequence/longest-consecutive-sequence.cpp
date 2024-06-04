class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;

        unordered_set<int> us;
        int longest = 1;

        for(int i = 0;i<nums.size(); i++)us.insert(nums[i]);

        for(auto i: us){
            if(us.find(i-1)==us.end()){
                int cnt =1;
                int x = i;

                while(us.find(x+1)!=us.end()){
                    cnt +=1;
                    x +=1;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};