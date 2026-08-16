class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (int x : stones){
            if (x % 3 == 0) c0++;
            if (x % 3 == 1) c1++;
            if (x % 3 == 2) c2++;
        }
        if (c0 % 2 == 0){
            return c1>0 && c2>0;
        }
        return abs(c1-c2) > 2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna