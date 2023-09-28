class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i, j, num;
        sort(intervals.begin(), intervals.end());
        for(i=0 ; i<intervals.size() ; i++)
        {
            if(temp.size()==0)
            {
                temp.push_back(intervals[i][0]);
                num = intervals[i][1];
            }
            else if(intervals[i][0]<=num)
            {
                num = max(num, intervals[i][1]);
            }
            else
            {
                temp.push_back(num);
                ans.push_back(temp);
                temp.clear();
                temp.push_back(intervals[i][0]);
                num = intervals[i][1];
            }
        }
        if(temp.size()>0)
        {
            temp.push_back(num);
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};