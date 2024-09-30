class MinStack {
public:
    stack<long long> st;  // Use long long for the stack to handle larger values
    long long mini = LLONG_MAX;  // Use LLONG_MAX instead of INT_MAX for larger range
    
    MinStack() { }
    
    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);  // Push the value directly if the stack is empty
        }
        else {
            if(val > mini) {
                st.push(val);  // Push the value directly if it's greater than the current minimum
            }
            else {
                st.push(2LL * val - mini);  // Store a modified value to keep track of the minimum
                mini = val;  // Update the minimum to the new pushed value
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long topVal = st.top();  // Use long long to hold the top value
        st.pop();
        if(topVal < mini) {
            mini = 2 * mini - topVal;  // Restore the previous minimum value if necessary
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long topVal = st.top();
        if(topVal < mini) {
            return mini;  // Return the current minimum if the stored value is modified
        }
        return topVal;  // Otherwise, return the top value
    }
    
    int getMin() {
        return mini;  // Return the current minimum
    }
};
