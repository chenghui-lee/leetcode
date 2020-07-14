class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans;
        double h = hour * 5;
        if (minutes > 0){
            h += (double)minutes/12;
        }
        if (h>60) h-= 60;
        double temp = abs(minutes-h);
        temp = min(temp, 60-temp);
        ans = temp * 6;
        if (ans>= 360) ans-= 360;
        return ans;
    }
};
