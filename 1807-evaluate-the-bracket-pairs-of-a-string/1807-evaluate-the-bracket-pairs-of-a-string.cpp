class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& k : knowledge){
            mp[k[0]] = k[1];
        }
        string ans = "";
        for (int i=0; i<s.size(); i++){
            if (s[i] == '('){
                string key;
                i++;
                while (s[i] != ')'){
                    key += s[i];
                    i++;
                }
                if (mp.find(key) != mp.end()) ans += mp[key];
                else ans += '?';
            }
            else ans += s[i];
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna