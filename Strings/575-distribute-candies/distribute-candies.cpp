class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st(candyType.begin(), candyType.end());
        int n = candyType.size();
        int total = st.size();
        return min(total, n/2);
        //Unordered_map can also be used but no use of frequemcy so set is better.
        //Initialization of st to directly candyType saves Runtime by 40%.
    }
};