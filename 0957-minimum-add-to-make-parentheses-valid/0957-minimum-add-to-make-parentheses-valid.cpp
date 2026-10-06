class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, ans = 0;
        for (char c : s){
            if (c == '(') open++;
            else{
                if (open > 0) open--;
                else ans++;
            }
        }
        return ans + open;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna