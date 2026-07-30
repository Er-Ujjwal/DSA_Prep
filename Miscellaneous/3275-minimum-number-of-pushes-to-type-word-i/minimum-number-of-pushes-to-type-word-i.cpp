class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        for (int i=0; i<word.size(); i++){
            ans += (i/8)+1;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna