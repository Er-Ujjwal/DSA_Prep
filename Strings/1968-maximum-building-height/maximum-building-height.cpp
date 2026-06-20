class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Add mandatory restriction for building 1
        restrictions.push_back({1, 0});
        // Add a loose upper bound for building n
        restrictions.push_back({n, n - 1});
        // Sort by building index
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();
        // Left -> Right pass
        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1]+dist);
        }
        // Right -> Left pass
        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1]+dist);
        }
        int ans = 0;
        // Find maximum achievable height between adjacent restrictions
        for (int i = 1; i < m; i++) {
            int leftPos = restrictions[i - 1][0];
            int leftHeight = restrictions[i - 1][1];
            int rightPos = restrictions[i][0];
            int rightHeight = restrictions[i][1];
            int dist = rightPos - leftPos;
            int peak = (leftHeight + rightHeight + dist) / 2;
            ans = max(ans, peak);
        }
        return ans;
    }
};