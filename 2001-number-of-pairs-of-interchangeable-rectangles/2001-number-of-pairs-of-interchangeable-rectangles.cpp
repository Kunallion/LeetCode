class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        
        unordered_map<double, int> mp;

        for(int i=0 ; i<rectangles.size() ; i++){
            mp[rectangles[i][0]/(double)rectangles[i][1]]++;
        }

        long long ans=0;

        for(int i=0 ; i<rectangles.size() ; i++){
            ans += --mp[rectangles[i][0]/(double)rectangles[i][1]];
        }

        return ans;
    }
};