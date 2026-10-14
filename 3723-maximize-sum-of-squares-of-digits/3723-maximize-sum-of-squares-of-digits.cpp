class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9*num) return "";
        string ans;
        for (int i=0; i<num; i++){
            int digit = min(9, sum);
            ans += char('0' + digit);
            sum -= digit;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna