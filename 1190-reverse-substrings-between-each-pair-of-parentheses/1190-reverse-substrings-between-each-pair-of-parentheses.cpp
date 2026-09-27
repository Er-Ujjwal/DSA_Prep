class Solution {
public:
    string reverseParentheses(string s) {
        string curr = "";
        stack<string> st;
        for (char c : s){
            if (c == '('){
                st.push(curr);
                curr = "";
            }
            else if (c == ')'){
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }
            else curr += c;
        }
        return curr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna