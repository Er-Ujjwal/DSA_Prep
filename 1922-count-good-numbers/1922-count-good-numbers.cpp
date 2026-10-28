class Solution {
public:
    long long MOD = 1e9+7;
    long long power(long long base, long long exp){
        long long res = 1;
        base %= MOD;
        while (exp){
            if (exp & 1) res = (res*base) % MOD;
            base = (base*base) % MOD;
            exp >>= 1;
        }        
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenCount = (n+1)/2;
        long long oddCount = n/2;
        long long evenResult = power(5, evenCount);
        long long oddResult = power(4, oddCount);
        return (int)((evenResult * oddResult) % MOD);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna