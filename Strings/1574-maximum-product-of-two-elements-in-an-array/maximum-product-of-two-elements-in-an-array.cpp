class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        for (int x : nums){
            if (x >= max1){
                max2 = max1;
                max1 = x;
            }
            else if (x > max2) max2 = x;
        }
        return (max1-1)*(max2-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna