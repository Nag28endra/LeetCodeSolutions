class Solution {
public:
    bool possible(vector<int> &bloomDay,int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0, nBouquet = 0;

        for (int i = 0; i<n; i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                nBouquet += cnt/k;
                cnt = 0; 
            }
        }
        nBouquet += cnt/k;
        return (nBouquet>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int n = bloomDay.size();
        long long val = m*1LL*k*1LL;
        if(val>n) return -1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if (possible(bloomDay,mid,m,k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    return low;      
    }
};