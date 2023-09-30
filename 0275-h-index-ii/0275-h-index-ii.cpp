class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0, high=citations.size()-1, mid, ans=0;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(citations[mid]>=citations.size()-mid)
            {
                if(citations.size()-mid>ans)
                    ans = citations.size()-mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};