class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        for (char c : word){
            if (isupper(c)) upper++;
        }
        return upper == 0 || upper == word.size() || 
               (upper == 1 && isupper(word[0]));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna