class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> A, B;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (img1[i][j]) A.push_back({i, j});
                if (img2[i][j]) B.push_back({i, j});
            }
        }
        unordered_map<int, int> freq;
        int ans = 0;
        for (auto [i, j] : A){
            for (auto [x, y] : B){
                int dx = x-i+n-1;
                int dy = y-j+n-1;
                int key = dx*(2*n-1) + dy;
                ans = max(ans, ++freq[key]);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna