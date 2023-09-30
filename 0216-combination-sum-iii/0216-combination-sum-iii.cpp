class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> temp, int sum, int index, int len, int k, int n)
    {
        if(sum==n && len==k){
            ans.push_back(temp);
            return;
        }
        if(index>=10 || sum>n || len>k)
            return;

        // exclude part
        solve(ans, temp, sum, index+1, len, k, n);

        // include part
        sum += index;
        temp.push_back(index);
        len += 1;
        solve(ans, temp, sum, index+1, len, k, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        int index=1;
        int sum=0;
        int len=0;

        solve(ans, temp, sum, index, len, k, n);

        return ans;
    }
};