class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int>mpp;
        int n = candyType.size();
        for (int i=0; i<n; i++){
            mpp[candyType[i]]++;
        }
        int total = mpp.size();
        return min(total, n/2);
    }
};