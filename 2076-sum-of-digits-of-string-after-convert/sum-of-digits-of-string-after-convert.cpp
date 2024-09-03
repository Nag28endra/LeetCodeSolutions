class Solution {
public:
    int sumOfDigits(int integer){
        int sum = 0;

        while(integer != 0){
            int rem = integer % 10;
            sum += rem;
            integer /= 10;
        }
        return sum;
    }
public:
    int getLucky(string s, int k) {
        
        if (s.length() == 0) return 0;
        string integer = "";
        for(int i = 0; i<s.length(); i++){
                integer += to_string(s[i] - 'a' + 1);
        }
        int ans = 0;
        for(char ch: integer){
            ans += ch - '0';
        }
        k -=1;
        while(k!=0){
            ans = sumOfDigits(ans);
            k--;
        }
        return ans;
    }
};