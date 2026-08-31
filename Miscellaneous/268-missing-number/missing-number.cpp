class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() +1;
        int sum = n*(n-1)/2;
        int actual_sum = 0;
        for (int x : nums) actual_sum += x;
        return sum - actual_sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna