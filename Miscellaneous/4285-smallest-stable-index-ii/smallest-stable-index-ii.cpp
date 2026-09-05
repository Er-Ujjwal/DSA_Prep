class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>suffixMin(n);
        suffixMin[n-1] = nums[n-1];
        for (int i=n-2; i>=0; i--){
            suffixMin[i] = min(nums[i], suffixMin[i+1]);
        }
        int prefixMax = 0;
        for (int i=0; i<n; i++){
            prefixMax = max(nums[i], prefixMax);
            if (prefixMax - suffixMin[i] <= k) return i;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna