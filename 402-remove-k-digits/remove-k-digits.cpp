class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        stack<char> st;

        for(int i= 0; i<num.size(); i++)
        {
            // check if stack has some values and the top is greater than current pop it out.
            while(!st.empty() && k>0 && (st.top() - '0' > num[i]-'0')){
                st.pop();
                k -=1;
            }
            st.push(num[i]);
        }
        // if there is still  k values are not removed
        while(k>0){
            st.pop();
            k -=1;
        }

        if(st.empty()) return "0";
        // store the resultant in the string.
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        //check if there are any leading zeros
        while(result.size() !=0 && result.back() == '0') result.pop_back();
        //reverse the result as it is taken in reverse order from the stack
        reverse(result.begin(),result.end());
        // check if the string is empty or not
        if(result.size() == 0) return "0";
        return result;
    }
};