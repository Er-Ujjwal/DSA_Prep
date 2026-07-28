class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // Sorting helps to pick cheapest first.
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int i=0; i<costs.size(); i++){
            //If cost > coin then we can't buy, so break....
            if (costs[i] > coins) break;
            // otherwise coins get reduced & icecream prchased..
            coins -= costs[i];
            count++;
        }
        return count;
    }
};