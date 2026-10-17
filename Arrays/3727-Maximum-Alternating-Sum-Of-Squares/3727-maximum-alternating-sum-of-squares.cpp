class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for (int i=0; i<n; i++){
            long long sq = 1LL * nums[i] * nums[i];
            if (i < n/2) ans -= sq;
            else ans += sq;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna