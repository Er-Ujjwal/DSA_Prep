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
        unordered_map<string, int> freq;
        int ans = 0;
        for (auto [i, j] : A){
            for (auto [x, y] : B){
                int dx = x-i;
                int dy = y-j;
                string key = to_string(dx) + "," + to_string(dy);
                ans = max(ans, ++freq[key]);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna