class Solution {
public:
    int findDays(vector<int> weights, int capacity){
        int load = 0;
        int days = 1;

        for(int i = 0; i<weights.size(); i++){
            if(load+weights[i]>capacity){
                days +=1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid = low + (high-low)/2;

            int requiredDays = findDays(weights,mid);
            if(requiredDays<=days){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }

};