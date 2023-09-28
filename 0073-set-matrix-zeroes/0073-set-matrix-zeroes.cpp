class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j;
        vector<int> rows;
        vector<int> cols;
        for(i=0 ; i<matrix.size() ; i++)
        {
            for(j=0 ; j<matrix[i].size() ; j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        if(rows.size()>0)
        {
            for(i=0 ; i<rows.size() ; i++)
            {
                for(j=0 ; j<matrix[0].size() ; j++)
                {
                    matrix[rows[i]][j] = 0;
                }
            }
        }
        if(cols.size()>0)
        {
            for(i=0 ; i<cols.size() ; i++)
            {
                for(j=0 ; j<matrix.size() ; j++)
                {
                    matrix[j][cols[i]] = 0;
                }
            }
        }
    }
};