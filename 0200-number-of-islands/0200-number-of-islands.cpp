class Solution {
public:
    
    void islands(vector<vector<char>> &grid, vector<vector<int>> &visited, pair<int,int> &point)
    {
        queue<pair<int,int>> q;
        q.push(point);

        while(!q.empty())
        {
            auto front = q.front();
            q.pop();

            if(front.first>0)
            {
                if(grid[front.first-1][front.second]=='1' && visited[front.first-1][front.second]==0)
                {
                    q.push({front.first-1, front.second});
                    visited[front.first-1][front.second] = 1;
                }
            }
            if(front.first<grid.size()-1)
            {
                if(grid[front.first+1][front.second]=='1' && visited[front.first+1][front.second]==0)
                {
                    q.push({front.first+1, front.second});
                    visited[front.first+1][front.second] = 1;
                }
            }
            if(front.second>0)
            {
                if(grid[front.first][front.second-1]=='1' && visited[front.first][front.second-1]==0)
                {
                    q.push({front.first, front.second-1});
                    visited[front.first][front.second-1] = 1;
                }
            }
            if(front.second<grid[0].size()-1)
            {
                if(grid[front.first][front.second+1]=='1' && visited[front.first][front.second+1]==0)
                {
                    q.push({front.first, front.second+1});
                    visited[front.first][front.second+1] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int i, j, count=0;
        vector<vector<int>> visited;
        vector<int> temp;
        for(i=0 ; i<grid.size() ; i++)
        {
            for(j=0 ; j<grid[i].size() ; j++)
            {
                temp.push_back(0);
            }
            visited.push_back(temp);
            temp.clear();
        }

        for(i=0 ; i<grid.size() ; i++)
        {
            for(j=0 ; j<grid[i].size() ; j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                    pair<int,int> point = {i, j};
                    islands(grid, visited, point);
                    count++;
                }
            }
        }
        return count;
    }
};