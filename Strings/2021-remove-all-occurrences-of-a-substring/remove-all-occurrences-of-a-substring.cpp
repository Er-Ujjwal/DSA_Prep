class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        while (s.length() >0 && pos < s.length()){
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }
};