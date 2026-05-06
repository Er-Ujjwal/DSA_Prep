class Solution {
public:
    bool isAlphaNumeric(char ch){
        if ((ch >=48 && ch <=57) || (ch >=65 && ch <=90) || (ch >=97 && ch<=122)){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        if (s.size() == 1 || s.size() == 0) return true; 
        while (start < end){
            if (!isAlphaNumeric(s[start])){
                start++; 
                continue;
            }
            if (!isAlphaNumeric(s[end])){
                end--;
                continue;
            } 
            if (tolower(s[start++]) != tolower(s[end--])) return false;
        }
        return true;
    }
};