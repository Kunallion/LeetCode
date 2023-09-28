class Solution {
private:
    void rotate(vector<vector<int>>& mat)
    {
        for(int i=0 ; i<mat.size() ; i++){
            for(int j=i ; j<mat[0].size() ; j++)
                swap(mat[i][j], mat[j][i]);
        }
        for(int i=0 ; i<mat.size() ; i++)
            reverse(mat[i].begin(), mat[i].end());
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        if(mat==target)
            return true;
        
        // rotate by 90 thrice
        int n=3;
        while(n--)
        {
            rotate(mat);
            if(mat==target)
                return true;
            
        }
        return false;
    }
};