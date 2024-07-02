class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> preSum(n);
        preSum[0] = chalk[0];
        for(int i = 1;i<n; i++){
            preSum[i] = chalk[i] + preSum[i-1];
        }
        k %=preSum[n-1];
        int low = 0;
        int high = n-1;
        int ans;

        while(low<=high){
            int mid = (low + high)>>1;
            if(preSum[mid]<=k) low = mid + 1;
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};