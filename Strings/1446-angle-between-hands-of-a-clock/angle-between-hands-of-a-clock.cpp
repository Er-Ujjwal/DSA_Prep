class Solution {
public:
    double angleClock(int hour, int minutes) {
        //Minute hand angle from 12 = 6deg*M -> 360deg in 60 min = 6deg/minute;
        //Hour hand angle from 12 = 0.5deg*H -> 360deg in 12hr = 30deg/hr = 0.5deg/mn;
        hour%= 12;
        double angle = abs(30*hour - 5.5*minutes);
        return min(angle, 360-angle);
    }
};