class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i, j, k;
        unordered_map<int, int> mp;
        for(i=0 ; i<board.size() ; i++)
        {
            for(j=0 ; j<board[i].size() ; j++)
            {
                if(board[i][j]!='.')
                {
                    mp[(int)(board[i][j])]++;
                    if(mp[(int)(board[i][j])]>1)
                    {
                        return false;
                    }
                }
            }
            mp.clear();
        }
        for(i=0 ; i<board[0].size() ; i++)
        {
            for(j=0 ; j<board.size() ; j++)
            {
                if(board[j][i]!='.')
                {
                    mp[(int)(board[j][i])]++;
                    if(mp[(int)(board[j][i])]>1)
                    {
                        return false;
                    }
                }
            }
            mp.clear();
        }

        for(i=0 ; i<9 ; i+=3)
        {
            for(j=0 ; j<9 ; j+=3)
            {
                mp.clear();
                mp[(int)(board[i][j])]++;
                mp[(int)(board[i][j+1])]++;
                mp[(int)(board[i][j+2])]++;
                mp[(int)(board[i+1][j])]++;
                mp[(int)(board[i+1][j+1])]++;
                mp[(int)(board[i+1][j+2])]++;
                mp[(int)(board[i+2][j])]++;
                mp[(int)(board[i+2][j+1])]++;
                mp[(int)(board[i+2][j+2])]++;
                for(auto it:mp)
                {
                    if(it.second>1 && it.first!='.')
                    {
                        return false;
                    }
                }
            }
            mp.clear();
        }
        return true;
    }
};