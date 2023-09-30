class Solution {
public:
    int countLiveNeighbours(vector<vector<int>> &arr, int x, int y)
    {
        int count=0;
        if(x>0 && arr[x-1][y]==1)
            count++;
        if(y>0 && arr[x][y-1]==1)
            count++;
        if(x<arr.size()-1 && arr[x+1][y]==1)
            count++;
        if(y<arr[0].size()-1 && arr[x][y+1]==1)
            count++;
        
        if(x>0 && y>0 && arr[x-1][y-1]==1)
            count++;
        if(x>0 && y<arr[0].size()-1 && arr[x-1][y+1]==1)
            count++;
        if(x<arr.size()-1 && y>0 && arr[x+1][y-1]==1)
            count++;
        if(x<arr.size()-1 && y<arr[0].size()-1 && arr[x+1][y+1]==1)
            count++;
            
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> arr(board.begin(), board.end());
        
        for(int i=0 ; i<board.size() ; i++)
        {
            for(int j=0 ; j<board[0].size() ; j++)
            {
                if(board[i][j]==0){
                    if(countLiveNeighbours(arr, i, j)==3)
                        board[i][j] = 1;
                }
                else if(countLiveNeighbours(arr, i, j)<2 || countLiveNeighbours(arr, i, j)>3)
                        board[i][j] = 0;
            }
        }
    }
};