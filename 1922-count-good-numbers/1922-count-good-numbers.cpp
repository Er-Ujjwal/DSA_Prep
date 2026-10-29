class Solution {
public:
    const int MOD = 1e9 + 7;
    int findPower(long long a, long long b){
        if (b == 0) return 1;
        long long half = findPower(a, b/2);
        long long result = (half * half) % MOD;
        if (b % 2) result = (result * a) % MOD;
        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long)findPower(5, (n+1)/2) * findPower(4, n/2) % MOD;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna