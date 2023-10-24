class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        long long int sum=0, prefixSum=0;
        int i, ans=0; 
        
        // Calculate Total Sum
        sum = accumulate(nums.begin(), nums.end(), 0LL);

        // Finding Valid Splits
        for(i=0 ; i<nums.size()-1 ; i++){

            prefixSum += nums[i];
            sum -= nums[i];

            if(prefixSum>=sum){
                ans++;
            }
        }
        
        // Return ans
        return ans;
    }
};