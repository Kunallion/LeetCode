class Solution {
private:
    bool isSafe(vector<string>& board, int n, int row, int col){

        // Check row
        int x = row;
        int y = col;
        while(y>=0){
            if(board[x][y]=='Q')
                return false;
            y--;
        }

        // Check upper left diagonal
        x = row;
        y = col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q')
                return false;
            x--;
            y--;
        }

        // check Lower Left diagonal
        x = row;
        y = col;
        while(x<n && y>=0){
            if(board[x][y]=='Q')
                return false;
            x++;
            y--;
        }

        return true;
    }
    void solve(vector<vector<string>>& ans, vector<string>& board, int n, int col){

        // Base Case
        if(col==n){
            ans.push_back(board);
            board.clear();
            return;
        }

        for(int i=0 ; i<n ; i++){
            if(isSafe(board, n, i, col)){
                board[i][col] = 'Q';
                solve(ans, board, n, col+1);
                board[i][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        
        string s = "";

        for(int i=0 ; i<n ; i++){
            s += '.';
        }

        vector<string> board(n, s);
        vector<vector<string>> ans;

        solve(ans, board, n, 0);

        return ans.size();
    }
};