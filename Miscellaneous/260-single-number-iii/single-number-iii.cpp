class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        if (nums[0] != nums[1]) ans.push_back(nums[0]);
        for (int i=1; i<n-1; i++) {
            if ((nums[i-1] != nums[i]) && (nums[i] != nums[i+1]))
                ans.push_back(nums[i]);
        }
        if (nums[n-1] != nums[n-2]) ans.push_back(nums[n-1]);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna