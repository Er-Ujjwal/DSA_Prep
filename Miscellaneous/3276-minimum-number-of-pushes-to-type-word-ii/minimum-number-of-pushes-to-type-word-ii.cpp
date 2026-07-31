class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for (char c : word){
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        for (int i=0; i<26; i++){
            if (freq[i]==0) break;
            ans += freq[i]*((i/8)+1);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna