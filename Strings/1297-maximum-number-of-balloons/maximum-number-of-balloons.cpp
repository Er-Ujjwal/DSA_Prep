class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>mpp;
        for (int i=0; i<text.size(); i++){
            mpp[text[i] - 'a']++;
        }
        return min(mpp['b'-'a'], min(mpp['a'-'a'], min(mpp['l'-'a']/2,
                    min(mpp['o'-'a']/2, mpp['n'-'a']))));
    }
};