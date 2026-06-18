class Solution {
public:
    double angleClock(int hour, int minutes) {
        double thet = abs(30*hour - 5.5*minutes);
        return min(thet,360-thet);
    }
};