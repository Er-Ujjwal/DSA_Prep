class Solution {
public:
    vector<vector<int>> dp;
    int fxn(int i, int j){
        if (i==0 && j==0) return 1;
        if (i<0 || j<0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int up = fxn(i-1, j);
        int left = fxn(i, j-1);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, -1));
        return fxn(m-1, n-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna