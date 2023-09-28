class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, low, high;
        set<vector<int>> s;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        for(i=0 ; i<nums.size() ; i++)
        {
            low = i+1, high = nums.size()-1;
            while(low<high)
            {
                if(nums[i]+nums[low]+nums[high]==0)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    s.insert(temp);
                    temp.clear();
                    low++;
                    high--;
                }
                else if((nums[i]+nums[low]+nums[high])>0)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};