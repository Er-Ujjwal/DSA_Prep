class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for (long long x = 1000; x<=n; x*=1000){
            ans += n-x+1;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna