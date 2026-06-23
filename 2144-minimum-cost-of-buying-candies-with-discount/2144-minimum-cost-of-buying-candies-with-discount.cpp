class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        // Descending sorting method :-  uses comparator fxn at last;
        sort(cost.begin(), cost.end(), greater<int>());
        int total = 0;
        // If using normal sorting then traverse backwards and chack for (n-i-1)%3
        for (int i=0; i<n; i++){
            if (i % 3 != 2){
                total += cost[i];
            }
        }
        return total;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna