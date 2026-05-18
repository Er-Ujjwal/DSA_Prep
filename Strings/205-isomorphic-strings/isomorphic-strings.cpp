class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arrST[256] = {0}, arrTS[256] = {0};
        for (int i=0; i<s.size(); i++){
            char c1 = s[i], c2 = t[i];
            if (arrST[c1] != arrTS[c2]) return false;
            arrST[c1] = i+1;
            arrTS[c2] = i+1;
        }
        return true;
    }
};