class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        long long int sum=0, prefixSum=0, minSum=LLONG_MAX;
        int i, ans; 
        
        // Calculate Total Sum
        sum = accumulate(nums.begin(), nums.end(), 0LL);

        // Calculating Average Difference
        for(i=0 ; i<nums.size()-1 ; i++){

            prefixSum += nums[i];
            sum -= nums[i];

            if(abs((int)(prefixSum/(i+1)) - (int)(sum/(nums.size()-1-i)))<minSum){
                minSum = abs((int)(prefixSum/(i+1)) - (int)(sum/(nums.size()-1-i)));
                ans = i;
            }
        }
        prefixSum += nums[i];
        if(abs((int)(prefixSum/nums.size()))<minSum)
            ans = nums.size()-1;
        
        // Return ans
        return ans;
    }
};