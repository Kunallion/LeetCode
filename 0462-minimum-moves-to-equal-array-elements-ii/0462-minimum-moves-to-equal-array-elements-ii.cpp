class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        // Find Median after sorting
        sort(nums.begin(), nums.end());
        int median = nums[nums.size()/2];

        // Add the differences of elements with the median to get ans
        int ans=0;
        for(int i=0 ; i<nums.size() ; i++){
            ans += abs(nums[i]-median);
        }
        return ans;
    }
};