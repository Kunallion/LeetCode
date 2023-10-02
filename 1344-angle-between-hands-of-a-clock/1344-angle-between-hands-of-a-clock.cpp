class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double minuteDegree = (minutes/(double)60)*360;

        if(hour==12)
            hour = 0;

        double hourDegree = ((hour+(minutes/(double)60))/12)*360;
        
        return min(abs(hourDegree-minuteDegree), 360-abs(hourDegree-minuteDegree));
    }
};