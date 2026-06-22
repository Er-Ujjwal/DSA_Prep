class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>mpp;
        for (int i=0; i<text.size(); i++){
            mpp[text[i] - 'a']++;
        }
        int b = mpp['b'-'a'];
        int a = mpp['a'-'a'];
        int l = mpp['l'-'a'] / 2;
        int o = mpp['o'-'a'] / 2;
        int n = mpp['n'-'a'];
        int res = min(b, min(a, min(l, min(o, n))));
        return res;

    }
};