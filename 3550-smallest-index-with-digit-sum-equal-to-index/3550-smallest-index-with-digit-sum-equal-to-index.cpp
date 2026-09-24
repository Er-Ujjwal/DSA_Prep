class Solution {
public:
    int digitSum(int digit){
        int sum = 0;
        while (digit > 0){
            sum += digit % 10;
            digit /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++){
            if (i == digitSum(nums[i])) return i;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna