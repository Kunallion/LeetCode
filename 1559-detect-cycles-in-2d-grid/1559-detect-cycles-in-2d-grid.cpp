class Solution {
private:
    bool checkCycle(vector<vector<char>>& grid, int row, int col, char cell, int parentRow, int parentCol, vector<vector<bool>>& visited){

        visited[row][col] = true;

        // Go down
        if(row<grid.size()-1 && grid[row+1][col]==cell){
            if(!visited[row+1][col]){
                if(checkCycle(grid, row+1, col, cell, row, col, visited)){
                    return true;
                }
            }

            // If the down cell is already visited and not the parent cell of current cell, then it means there is a cycle, so return true
            else if((row+1)!=parentRow || col!=parentCol){
                return true;
            }
        }

        // Go up
        if(row>0 && grid[row-1][col]==cell){
            if(!visited[row-1][col]){
                if(checkCycle(grid, row-1, col, cell, row, col, visited)){
                    return true;
                }
            }

            // If the upper cell is already visited and not the parent cell of current cell, then it means there is a cycle, so return true
            else if((row-1)!=parentRow || col!=parentCol){
                return true;
            }
        }

        // Go Left
        if(col>0 && grid[row][col-1]==cell){
            if(!visited[row][col-1]){
                if(checkCycle(grid, row, col-1, cell, row, col, visited)){
                    return true;
                }
            }

            // If the left cell is already visited and not the parent cell of current cell, then it means there is a cycle, so return true
            else if(row!=parentRow || (col-1)!=parentCol){
                return true;
            }
        }

        // Go Right
        if(col<grid[0].size()-1 && grid[row][col+1]==cell){
            if(!visited[row][col+1]){
                if(checkCycle(grid, row, col+1, cell, row, col, visited)){
                    return true;
                }
            }

            // If the right cell is already visited and not the parent cell of current cell, then it means there is a cycle, so return true
            else if(row!=parentRow || (col+1)!=parentCol){
                return true;
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){

                // Traverse only those cells which are not already visited
                if(!visited[i][j]){
                    if(checkCycle(grid, i, j, grid[i][j], -1, -1, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};