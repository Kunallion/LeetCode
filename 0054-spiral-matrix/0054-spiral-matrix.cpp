class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i, total, count=0, sr=0, er=matrix.size()-1, sc=0, ec=matrix[0].size()-1;
        total = (er+1)*(ec+1);
        vector<int> ans;

        while(count<total)
        {
            for(i=sc ; i<=ec ; i++)
            {
                ans.push_back(matrix[sr][i]);
                count++;
            }
            if(count==total)
                break;
            sr++;
            for(i=sr ; i<=er ; i++)
            {
                ans.push_back(matrix[i][ec]);
                count++;
            }
            if(count==total)
                break;
            ec--;
            for(i=ec ; i>=sc ; i--)
            {
                ans.push_back(matrix[er][i]);
                count++;
            }
            if(count==total)
                break;
            er--;
            for(i=er ; i>=sr ; i--)
            {
                ans.push_back(matrix[i][sc]);
                count++;
            }
            if(count==total)
                break;
            sc++;
        }
        return ans;
    }
};