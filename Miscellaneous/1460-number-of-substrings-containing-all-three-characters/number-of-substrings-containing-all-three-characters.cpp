class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3,0);
        int left = 0, ans = 0;
        int n = s.size();
        for (int right=0; right<n; right++){
            count[s[right] - 'a']++;
            
            while (count[0] >0 && count[1] >0 && count[2] >0){
                ans += (n-right);
                count[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna