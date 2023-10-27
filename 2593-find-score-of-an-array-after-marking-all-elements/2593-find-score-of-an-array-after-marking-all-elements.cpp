class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        long long sum=0;
        map<pair<int,int>, int> mp;
        for(int i=0 ; i<nums.size() ; i++){
            mp[{nums[i], i}]++;
        }

        for(auto it:mp){
            if(nums[it.first.second]!=-1){
                sum += it.first.first;
                if(it.first.second+1<nums.size()){
                    nums[it.first.second+1] = -1;
                }
                if(it.first.second-1>=0){
                    nums[it.first.second-1] = -1;
                }
            }
        }
        return sum;
    }
};