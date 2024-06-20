class Solution {
public:
    bool canWePlace(vector<int> &position, int pos, int m){
        int cntM = 1;
        int last = position[0];
        int n = position.size();

        for(int i = 1; i<n; i++){
            if(position[i]-last>=pos){
                cntM++;
                last = position[i];
            }
            if(cntM>=m)return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[n-1]-position[0];

        while(low<=high){
            int mid = low + (high-low)/2;

            if(canWePlace(position,mid,m)==true)low = mid+1;
            else high = mid - 1;
        }
        return high;
    }
};