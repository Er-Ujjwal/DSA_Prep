class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for (char c : s){
            mpp[c]++;
        }
        vector<string>bucket(s.size() + 1);
        for (auto &[ch, freq] : mpp){
            bucket[freq] += string(freq, ch);
        }
        string ans;
        for (int i=s.size(); i>=1; i--){
            ans += bucket[i];
        }
        return ans;
    }
};