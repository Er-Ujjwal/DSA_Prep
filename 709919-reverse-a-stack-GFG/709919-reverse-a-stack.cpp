class Solution {
  public:
    void reverseStack(stack<int> &st) {
        if (st.empty()) return;
        int top = st.top();
        st.pop();
        reverseStack(st);
        stack<int> temp;
        while (!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        st.push(top);
        while (!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna