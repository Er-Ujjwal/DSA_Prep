class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna