class Solution {
public:
    string largestOddNumber(string num) {
        for (int i= num.size()-1; i>=0; i--){
            if ((num[i]-'0') %2 != 0){
                return num.substr(0, i+1); //checks from last end for max result
            }                              //substring helps to show only req. part
        }
        return "";
    }
};