class Solution {
public:
    void solve(vector<int> &nums, vector<int> subset, set<vector<int>> &s, int index)
    {
        if(index>=nums.size())
        {
            s.insert(subset);
            return;
        }

        // exclude part
        solve(nums, subset, s, index+1);

        // include part
        int element = nums[index];
        subset.push_back(element);
        solve(nums, subset, s, index+1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> subset;
        
        int index=0;
        sort(nums.begin(), nums.end());
        solve(nums, subset, s, index);

        for(auto it:s)
            ans.push_back(it);

        return ans;
    }
};