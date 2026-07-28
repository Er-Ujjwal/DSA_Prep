class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int height = 0, maxi = INT_MIN;
        for (int i=0; i<gain.size(); i++){
            height += gain[i];
            gain[i] = height;
            maxi = max(maxi, gain[i]);
        }
        return max(0, maxi);
    }
};