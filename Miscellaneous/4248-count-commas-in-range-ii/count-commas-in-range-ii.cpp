class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for (long long base = 1000; base <= n; base*=1000){
            ans += n - base + 1;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna