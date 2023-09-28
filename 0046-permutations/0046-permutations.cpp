class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>>& ans, int index)
    {
        // base case
        if(index>=nums.size())
        {
            ans.push_back(nums);
            return;
        }

        // Recursion
        for(int i=index ; i<nums.size() ; i++)
        {
            swap(nums[i], nums[index]);
            solve(nums, ans, index+1);

            // BackTracking
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        int index=0;
        solve(nums, ans, index);

        return ans;
    }
};