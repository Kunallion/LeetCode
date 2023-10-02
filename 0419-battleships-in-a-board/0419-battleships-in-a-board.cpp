class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int i, j, k, count=0;
        for(i=0 ; i<board.size() ; i++)
        {
            for(j=0 ; j<board[i].size() ; j++)
            {
                if(board[i][j]=='X')
                {
                    count++;
                    if(i<board.size())
                    {
                        for(k=i+1 ; k<board.size() ; k++)
                        {
                            if(board[k][j]=='X')
                                board[k][j] = '.';
                            else
                                break;
                        }
                    }
                    if(j<board[i].size())
                    {
                        for(k=j+1 ; k<board[i].size() ; k++)
                        {
                            if(board[i][k]=='X')
                                board[i][k] = '.';
                            else
                                break;
                        }
                    }
                }
            }
        }
        return count;
    }
};