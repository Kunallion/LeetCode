class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        
        int n = nums.size();
        int ans=0, sum=0;
        unordered_map<int,int> mp;

        for(int i=0 ; i<n ; i++){

            // Keep adding nums[i] to sum
            sum += nums[i];

            // If sum == target or (sum-target) is present, then increment ans and make sum=0 and clear the map. It is because once we got a subarray, we cannot use it again, and hence we need to clear our hashmap and also make sum=0
            if(sum==target || mp.find(sum-target)!=mp.end()){
                ans++;
                sum=0;
                mp.clear();
            }
            // else we insert sum in our map
            else{
                mp[sum]++;
            }
        }
        return ans;
    }
};