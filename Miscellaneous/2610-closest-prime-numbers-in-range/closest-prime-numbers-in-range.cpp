class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right+1, true);
        sieve[0] = sieve[1] = false;
        for (int i=2; i*i<=right; i++){
            if (sieve[i]){
                for (int j=i*i; j<=right; j+=i) sieve[j] = false;
            }
        }
        vector<int> ans = {-1, -1};
        int prev = -1, minDiff = INT_MAX;
        for (int i=left; i<=right; i++){
            if (sieve[i]){
                if (prev != -1){
                    int diff = i - prev;
                    if (diff < minDiff){
                        minDiff = diff;
                        ans = {prev, i};
                    }
                }
                prev = i;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna