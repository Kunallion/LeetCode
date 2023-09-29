class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i, j;
        vector<vector<int>> ans;
        vector<int> arr;
        for(i=0 ; i<=rowIndex ; i++)
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
                    arr.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
                arr.push_back(1);
            }
            ans.push_back(arr);
            arr.clear();
        }
        return ans[rowIndex];
    }
};