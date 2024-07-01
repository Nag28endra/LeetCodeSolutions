class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        __int128_t res = 1;

        while(low<=high){
            __int128_t mid = (low + high)>>1;

            if (mid*mid<=x){
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return res;
    }
};