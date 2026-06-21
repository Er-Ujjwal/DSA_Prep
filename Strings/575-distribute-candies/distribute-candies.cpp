class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>st;
        int n = candyType.size();
        for (int x : candyType){
            st.insert(x);
        }
        int total = st.size();
        return min(total, n/2);
    }
};