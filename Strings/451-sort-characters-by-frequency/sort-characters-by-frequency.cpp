class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (auto ch : s)
            freq[ch]++;
        vector<vector<char>> bucketData(s.length() + 1);
        for (auto [ch, fq] : freq) {
            bucketData[fq].push_back(ch);
        }
        string ans = "";
        for (int fq = s.length(); fq >= 1; fq--) {
            for (auto ch : bucketData[fq]) {
                ans.append(fq, ch);
            }
        }
        return ans;
    }
};