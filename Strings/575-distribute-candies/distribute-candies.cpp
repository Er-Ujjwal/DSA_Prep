class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st(candyType.begin(), candyType.end());
        int n = candyType.size();
        int total = st.size();
        return min(total, n/2);
    }
};