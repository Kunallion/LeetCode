class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        vector<int> ans(intervals.size(), -1);

        map<vector<int>, int> mp;
        for(int i=0 ; i<intervals.size() ; i++){
            mp[intervals[i]] = i;
        }

        sort(intervals.begin(), intervals.end());

        for(int i=0 ; i<intervals.size() ; i++){

            int left = intervals[i][0];
            int right = intervals[i][1];
            int index=-1;

            int low=i, high=intervals.size()-1, mid;
            while(low<=high){
                mid = low+(high-low)/2;
                if(intervals[mid][0]>=right){
                    index=mid;
                    high = mid-1;
                }
                else if(intervals[mid][0]>right){
                    high = mid-1;
                }
                else if(intervals[mid][0]<right){
                    low = mid+1;
                }
            }

            if(index!=-1){
                ans[mp[intervals[i]]] = mp[intervals[index]];
            }

        }
        return ans;
    }
};