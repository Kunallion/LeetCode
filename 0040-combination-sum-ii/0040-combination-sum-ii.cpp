class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>> &ans, vector<int>& temp, int index, int sum, int target)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(sum>target)
            return;

        for(int i=index ; i<candidates.size() ; i++)
        {
            if(i!=index && candidates[i]==candidates[i-1])
                continue;
            
            sum += candidates[i];
            temp.push_back(candidates[i]);
            solve(candidates, ans, temp, i+1, sum, target);
            sum -= candidates[i];
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        int index=0;
        int sum=0;

        sort(candidates.begin(), candidates.end());
        solve(candidates, ans, temp, index, sum, target);

        return ans;
    }
};