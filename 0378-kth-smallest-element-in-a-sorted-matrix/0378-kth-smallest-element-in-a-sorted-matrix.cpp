class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i, j;
        vector<int> ans;
        for(i=0 ; i<matrix.size() ; i++)
        {
            for(j=0 ; j<matrix[i].size() ; j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};