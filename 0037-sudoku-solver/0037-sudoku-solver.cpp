class Solution {
private:
    bool isSafe(int row, int col, vector<vector<char>>& board, int val)
    {
        for(int i=0 ; i<9 ; i++)
        {
            if(board[row][i]==val+48)
                return false;
            if(board[i][col]==val+48)
                return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val+48)
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int row=0; row<board.size() ; row++)
        {
            for(int col=0; col<board[0].size() ; col++)
            {
                if(board[row][col]=='.')
                {
                    for(int val=1 ; val<=9 ; val++)
                    {
                        if(isSafe(row, col, board, val))
                        {
                            board[row][col] = val+48;

                            // Recursion
                            if(solve(board))
                                return true;
                            
                            // BackTracking
                            else
                            {
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }

        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};