class Solution {
public:
    int dateToDays(string dateStr){
        int month = stoi(dateStr.substr(0,2));
        int day = stoi(dateStr.substr(3,2));
        vector<int> daysPerMonth = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        return accumulate(daysPerMonth.begin(), daysPerMonth.begin()+month, 0) + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveA = dateToDays(arriveAlice);
        int leaveA = dateToDays(leaveAlice);
        int arriveB = dateToDays(arriveBob);
        int leaveB = dateToDays(leaveBob);

        int startOverlap = max(arriveA, arriveB);
        int endOverlap = min(leaveA, leaveB);
        return max(0, endOverlap - startOverlap + 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna