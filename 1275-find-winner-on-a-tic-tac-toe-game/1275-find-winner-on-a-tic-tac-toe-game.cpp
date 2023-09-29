class Solution {
private:
    bool checkWinnerA( vector<vector<char>>& mat)
    {
        if(mat[0][0]=='1')
        {
            if(mat[0][0]=='1' && mat[0][1]=='1' && mat[0][2]=='1')
                return true;
            if(mat[0][0]=='1' && mat[1][0]=='1' && mat[2][0]=='1')
                return true;
            if(mat[0][0]=='1' && mat[1][1]=='1' && mat[2][2]=='1')
                return true;
        }
        if(mat[0][1]=='1' && mat[1][1]=='1' && mat[2][1]=='1')
            return true;
        if(mat[0][2]=='1')
        {
            if(mat[0][2]=='1' && mat[1][1]=='1' && mat[2][0]=='1')
                return true;
            if(mat[0][2]=='1' && mat[1][2]=='1' && mat[2][2]=='1')
                return true;
        }
        if(mat[1][0]=='1' && mat[1][1]=='1' && mat[1][2]=='1')
            return true;
        if(mat[2][0]=='1' && mat[2][1]=='1' && mat[2][2]=='1')
            return true;

        return false;
    }

    bool checkWinnerB( vector<vector<char>>& mat)
    {
        if(mat[0][0]=='0')
        {
            if(mat[0][0]=='0' && mat[0][1]=='0' && mat[0][2]=='0')
                return true;
            if(mat[0][0]=='0' && mat[1][0]=='0' && mat[2][0]=='0')
                return true;
            if(mat[0][0]=='0' && mat[1][1]=='0' && mat[2][2]=='0')
                return true;
        }
        if(mat[0][1]=='0' && mat[1][1]=='0' && mat[2][1]=='0')
            return true;
        if(mat[0][2]=='0')
        {
            if(mat[0][2]=='0' && mat[1][1]=='0' && mat[2][0]=='0')
                return true;
            if(mat[0][2]=='0' && mat[1][2]=='0' && mat[2][2]=='0')
                return true;
        }
        if(mat[1][0]=='0' && mat[1][1]=='0' && mat[1][2]=='0')
            return true;
        if(mat[2][0]=='0' && mat[2][1]=='0' && mat[2][2]=='0')
            return true;

        return false;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {

        vector<vector<char>> mat(3, vector<char>(3, -1));
        string ans = "Pending";

        for(int i=0 ; i<moves.size() ; i++)
        {
            if(i%2==0)
                mat[moves[i][0]][moves[i][1]] = '1';
            else
                mat[moves[i][0]][moves[i][1]] = '0';
        }

        if(checkWinnerA(mat))
            ans = 'A';
        else if(checkWinnerB(mat))
            ans = 'B';
        else if(moves.size()==9)
            ans = "Draw";

        return ans;
    }
};