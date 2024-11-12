class StockSpanner {
public:
    // stack to store price-index pair.
    stack<pair<int,int>> st;
    int idx = -1;
    //function to clear the stack.
    void clear(stack<pair<int,int>> st){
        while(!st.empty())st.pop();
    }
    StockSpanner() {
        idx = -1;
        //clear the stack
        clear(st);
    }
    
    int next(int price) {
        idx += 1;
        while(!st.empty() && st.top().first <= price) st.pop();
        int ans = idx - (st.empty()?-1:st.top().second);
        st.push({price,idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */