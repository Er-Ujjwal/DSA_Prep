class Solution {
public:
    bool isPrime(int num){
        if (num < 2) return false;
        int count = 0;
        for (int i=2; i*i<=num; i++){
            if (num%i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1, -1};
        int prev = -1, minDiff = INT_MAX;
        for (int i=left; i<=right; i++){
            if (isPrime(i)){
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