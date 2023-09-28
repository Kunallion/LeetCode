class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n)
    {
        int x = row;
        int y = col;
        // Check if any queen present in same row
        while(y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            y--;
        }

        // Check in upper left diagonal
        x = row;
        y = col;
        while(x>=0 && y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            x--;
            y--;
        }

        // Check in lower left diagonal
        x = row;
        y = col;
        while(x<n && y>=0)
        {
            if(board[x][y]=='Q')
                return false;
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<string>>& ans, vector<string>& board, int n)
    {
        // Base Case
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        // Solve for 1 Case, rest Recursion will handle
        for(int i=0 ; i<n ; i++)
        {
            if(isSafe(board, i, col, n))
            {
                board[i][col] = 'Q';
                solve(col+1, ans, board, n);
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        string s="";
        for(int i=0 ; i<n ; i++)
            s += '.';

        vector<string> board(n, s);

        solve(0, ans, board, n);

        return ans;
    }
};