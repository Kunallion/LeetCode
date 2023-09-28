class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i, j, low, high;
        long long int sum;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        if(nums.size()<4)
        {
            return {};
        }
        for(i=0 ; i<nums.size()-3 ; i++)
        {
            for(j=i+1 ; j<nums.size()-2 ; j++)
            {
                low = j+1, high = nums.size()-1;
                while(low<high)
                {
                    sum=0;
                    sum += nums[i];
                    sum += nums[j];
                    sum += nums[low];
                    sum += nums[high];
                    if(sum<INT_MIN || sum<target)
                        low++;
                    else if(sum>INT_MAX || sum>target)
                        high--;
                    else if(sum==target)
                    {
                        s.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};