class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return nums[i] < nums[j];
        });
        vector<int> ans(n);
        for (int i=0; i<n; ){
            int j=i+1;
            while (j<n && nums[idx[j]] - nums[idx[j-1]] <= limit){
                j++;
            }
            vector<int> positions(idx.begin()+i, idx.begin()+j);
            sort(positions.begin(), positions.end());
            for (int k=i; k<j; k++){
                ans[positions[k-i]] = nums[idx[k]];
            }
            i=j;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna