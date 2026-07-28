class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<long long>> cnt(n, vector<long long>(n, 0));
        dp[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;

        vector<pair<int, int>> dir = {{1,0}, {0,1}, {1,1}};
        for (int i=n-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                if (board[i][j] == 'X' || board[i][j] == 'S') continue;
                int best = -1;
                long long ways = 0;
                for (auto &[dx, dy] : dir){
                    int ni = i + dx;
                    int nj = j + dy;
                    if (ni >= n || nj >= n) continue;
                    if (dp[ni][nj] == -1) continue;
                    if (dp[ni][nj] > best){
                        best = dp[ni][nj];
                        ways = cnt[ni][nj];
                    }
                    else if (dp[ni][nj] == best){
                        ways = (ways + cnt[ni][nj]) % MOD;
                    }
                }
                if (best == -1) continue;
                dp[i][j] = best;
                if (board[i][j] != 'E'){
                    dp[i][j] += board[i][j] - '0';
                }
                cnt[i][j] = ways % MOD;
            }
        }
        if (dp[0][0] == -1) return {0,0};
        return {dp[0][0], (int)(cnt[0][0] % MOD)};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna