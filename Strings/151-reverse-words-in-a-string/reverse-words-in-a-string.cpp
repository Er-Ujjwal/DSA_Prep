class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), start = 0, end = 0;
        reverse(s.begin(), s.end());
        while (start < n){
            while (start < n && s[start] == ' ') start ++;
            if (start >= n) break;
            if (end != 0) s[end++] = ' ';
            int j = start;
            while (j < n && s[j] != ' '){
                s[end++] = s[j++];
            }
            reverse(s.begin() + end - (j-start), s.begin() + end);
            start = j;
        }
        s.resize(end);
        return s;
    }
};