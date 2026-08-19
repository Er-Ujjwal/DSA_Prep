class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, set<int>> mpp;
        for (auto &x : reservedSeats){
            mpp[x[0]].insert(x[1]);
        }
        int ans = (n-mpp.size())*2;
        for (auto &[row, seats] : mpp){
            bool left = true, middle = true, right = true;
            for (int i=2; i<=5; i++){
                if (seats.count(i)) left = false;
            }
            for (int i=4; i<=7; i++){
                if (seats.count(i)) middle = false;
            }
            for (int i=6; i<=9; i++){
                if (seats.count(i)) right = false;
            }
            if (left && right) ans += 2;
            else if (left || middle || right) ans +=1;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna