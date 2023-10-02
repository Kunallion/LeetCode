class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i, j, ans=0;
        for(i=0 ; i<grid.size() ; i++)
        {
            for(j=0 ; j<grid[i].size() ; j++)
            {
                if(grid[i][j]==1)
                {
                    if(i==0 || grid[i-1][j]==0)
                    {
                        ans++;
                    }
                    if(i==grid.size()-1 || grid[i+1][j]==0)
                    {
                        ans++;
                    }
                    if(j==0 || grid[i][j-1]==0)
                    {
                        ans++;
                    }
                    if(j==grid[i].size()-1 || grid[i][j+1]==0)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};