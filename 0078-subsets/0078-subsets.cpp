class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalSubsets = 1 << n;
        vector<vector<int>> result;
        for (int i=0; i<totalSubsets; i++){
            vector<int> currentSubset;
            for (int j=0; j<n; j++){
                if ((i & (1 << j)) != 0){
                    currentSubset.push_back(nums[j]);
                }
            }
            result.push_back(currentSubset);
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna