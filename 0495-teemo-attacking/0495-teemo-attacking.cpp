class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int i, time=0;
        for(i=0 ; i<timeSeries.size()-1 ; i++)
        {
            if(timeSeries[i]+duration-1<timeSeries[i+1])
            {
                time += duration;
            }
            else
            {
                time += timeSeries[i+1]-timeSeries[i];
            }
        }
        time += duration;
        return time;
    }
};