class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, ans = 0;
        for (char c : s){
            if (c == '('){
                depth++;
                ans = max(ans, depth);
            }
            else if (c == ')') depth--;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna