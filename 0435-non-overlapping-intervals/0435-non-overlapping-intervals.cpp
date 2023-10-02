class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1]<b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int i, prev=0, count=1, ans;
        for(i=1 ; i<intervals.size() ; i++)
        {
            if(intervals[prev][1]<=intervals[i][0])
            {
                count++;
                prev = i;
            }
        }
        ans = intervals.size()-count;
        return ans;
    }
};