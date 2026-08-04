class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> present(101, false);
        int mn = 101, mx = 0;
        for (int x : nums){
            present[x] = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        vector<int> ans;
        for (int i=mn+1; i<mx; i++){
            if (!present[i]) ans.push_back(i);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna