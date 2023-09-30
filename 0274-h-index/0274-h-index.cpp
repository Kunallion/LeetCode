class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i;
        sort(citations.begin(), citations.end());
        int ans=citations[0];
        for(i=citations.size() ; i>0 ; i--)
        {
            if(citations[citations.size()-i]>=i)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};