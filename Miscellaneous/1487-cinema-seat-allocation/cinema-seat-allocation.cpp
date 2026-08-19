class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int>mp;
        for (auto &x : reservedSeats){
            int row = x[0], seat = x[1];
            if (seat >=2 && seat <=9) mp[row] |= (1 << seat);
        }
        int ans = (n-mp.size())*2;
        for (auto &[row, mask] : mp){
            bool left = !(mask & ((1<<2) | (1<<3) | (1<<4) | (1<<5)));
            bool middle = !(mask & ((1<<4) | (1<<5) | (1<<6) | (1<<7)));
            bool right = !(mask & ((1<<6) | (1<<7) | (1<<8) | (1<<9)));
            if (left && right) ans += 2;
            else if (left || middle || right) ans += 1;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna