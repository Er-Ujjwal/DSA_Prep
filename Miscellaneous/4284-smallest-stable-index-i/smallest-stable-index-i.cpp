class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for (int i=0; i<nums.size(); i++){
            int mx = *max_element(nums.begin(), nums.begin()+i+1);
            int mn = *min_element(nums.begin()+i, nums.end());
            int stbl = mx-mn;
            if (stbl <= k) return i; 
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna