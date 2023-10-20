class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        
        int x=0, o=0;
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[i].size() ; j++){
                if(board[i][j]=='X')
                    x++;
                else if(board[i][j]=='O')
                    o++;
            }
        }
        if(o-x>=1 || (o+x)>9 || (x-o)>=2)
            return false;
        if(((board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X') || (board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X') || (board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X') || (board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X') || (board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X') || (board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X') || (board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X') || (board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')) && x==o)
            return false;
        if(((board[0][0]=='O' && board[0][1]=='O' && board[0][2]=='O') || (board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O') || (board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O') || (board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O') || (board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O') || (board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O') || (board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O') || (board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')) && x>o)
            return false;
        return true;
    }
};