class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> arr;
        int i, j, k;
        for(i=0 ; i<numRows ; i++)
        {
            if(i==0)
            {
                arr.push_back(1);
            }
            else if(i==1)
            {
                arr.push_back(1);
                arr.push_back(1);
            }
            else
            {
                arr.push_back(1);
                for(j=1 ; j<i ; j++)
                {
                    k = ans[i-1][j-1] + ans[i-1][j];
                    arr.push_back(k);
                }
                arr.push_back(1);
            }
            ans.push_back(arr);
            arr.clear();
        }
        return ans;
    }
};