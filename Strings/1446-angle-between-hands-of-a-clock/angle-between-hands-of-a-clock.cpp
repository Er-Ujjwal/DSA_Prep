class Solution {
public:
    double angleClock(int hour, int minutes) {
        //Minute hand angle from 12 = 6deg*M -> 360deg in 60 min = 6deg/minute;
        //Hour hand angle from 12 = 0.5deg*H -> 360deg in 12hr = 30deg/hr =0.5deg/mn;
        //For neglecting -ve value, taking absolute value here -> abs();
        hour%= 12;
        double minuteAngle = 6.0 * minutes;
        double hourAngle = 30.0 * hour + 0.5 * minutes;
        double angle = abs(hourAngle - minuteAngle);
        return min(angle, 360.0 - angle);
    }
};