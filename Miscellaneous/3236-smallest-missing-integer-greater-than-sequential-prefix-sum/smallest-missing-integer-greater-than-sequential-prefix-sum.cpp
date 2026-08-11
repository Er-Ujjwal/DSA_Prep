class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int sum  = nums[0];
        int i=1;
        while (i < nums.size() && nums[i] == nums[i-1]+1){
            sum += nums[i];
            i++;
        }
        while (st.count(sum)) sum++;
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna