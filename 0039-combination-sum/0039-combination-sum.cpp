class Solution {
public:
    void solve(vector<int> &candidates, set<vector<int>> &s, vector<int> temp, int index, int sum, int target)
    {
        if(sum==target)
        {
            s.insert(temp);
            return;
        }
        if(index>=candidates.size() || sum>target)
        {
            return;
        }

        // exclude part
        solve(candidates, s, temp, index+1, sum, target);

        // include part and stay on same index
        sum += candidates[index];
        temp.push_back(candidates[index]);
        solve(candidates, s, temp, index, sum, target);

        // include part and move forward
        sum += candidates[index];
        temp.push_back(candidates[index]);
        solve(candidates, s, temp, index+1, sum, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> temp;

        int index=0;
        int sum=0;

        solve(candidates, s, temp, index, sum, target);
        for(auto it:s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};