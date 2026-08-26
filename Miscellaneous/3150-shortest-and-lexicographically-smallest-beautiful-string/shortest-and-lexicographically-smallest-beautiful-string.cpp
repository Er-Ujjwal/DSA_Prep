class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, ones = 0;
        string ans = "";
        for (int right = 0; right<n; ++right){
            if (s[right] == '1') ones++;
            
            while (left <= right && (ones > k || (s[left] == '0' && ones == k))){
                if (s[left] == '1') ones--;
                left++;
            }
            if (ones == k){
                string cur = s.substr(left, right-left+1);
                if (ans.empty() || cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans)) ans = cur;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna