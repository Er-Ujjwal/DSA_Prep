class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i=n ;; i++){
            int product = 1;
            int x = i;
            while (x > 0){
                product *= (x%10);
                x /= 10;
            }
            if (product % t == 0) return i;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna