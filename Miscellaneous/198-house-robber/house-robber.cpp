class Solution {
public:
    int dp[401];
    int f(int i, vector<int>&nums){
        if (i >= nums.size()) return 0;
        if(dp[i]!=-1)return dp[i];
        int r = nums[i] + f(i+2, nums);
        int nr = 0 + f(i+1, nums);
        return dp[i]=max(r, nr);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0 ,nums);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna