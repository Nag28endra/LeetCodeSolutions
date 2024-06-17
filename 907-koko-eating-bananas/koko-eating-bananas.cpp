class Solution {
public:
    int findMax(vector<int> &piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0; i<n; i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    long long calculateTotalHours(vector<int> &piles, int hours){
        int n = piles.size();
        long long totalHours = 0;
        for(int i = 0 ; i<n; i++){
           totalHours += ceil( (double)piles[i] / (double) hours);
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        // int ans = INT_MAX;

        while(low<=high){
            int mid = low + (high-low)/2;

            long long totalhours = calculateTotalHours(piles,mid);
            if(totalhours<=h){
                // ans = min(ans,mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};