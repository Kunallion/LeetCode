class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int i, j, k=0, flag=0;

        vector<int> temp;
        vector<int> ans;

        for(i=0 ; i<mat.size() ; i++)
        {
            k=i;
            for(j=0 ; j<mat[0].size() && j<=i ; j++)
            {
                temp.push_back(mat[k][j]);
                k--;
            }

            if(flag==0)
            {
                for(k=0 ; k<temp.size() ; k++)
                    ans.push_back(temp[k]);
                flag=1;
            }
            else
            {
                for(int k=temp.size()-1 ; k>=0 ; k--)
                    ans.push_back(temp[k]);
                flag=0;
            }
            temp.clear();
        }

        for(i=1 ; i<mat[0].size() ; i++)
        {
            k = mat.size()-1;
            for(j=i ; k>=0 && j<mat[0].size() ; j++)
            {
                temp.push_back(mat[k][j]);
                k--;
            }

            if(flag==0)
            {
                for(k=0 ; k<temp.size() ; k++)
                    ans.push_back(temp[k]);
                flag=1;
            }
            else
            {
                for(int k=temp.size()-1 ; k>=0 ; k--)
                    ans.push_back(temp[k]);
                flag=0;
            }
            temp.clear();
        }
        return ans;
    }
};