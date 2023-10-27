class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }

        int ans=0, count=1, ele;
        float sq;

        for(auto it:mp){
            count=1;
            sq = sqrt(it.first);
            ele = sq;
            if(ele==sq){
                while(true){
                    if(mp.find(ele)!=mp.end()){
                        count++;
                        sq = sqrt(ele);
                        ele = sq;
                        if(ele!=sq)
                            break;
                    }
                    else{
                        break;
                    }
                }
            }
            ans = max(ans, count);
        }
        if(ans==1)
            return -1;
        return ans;
    }
};