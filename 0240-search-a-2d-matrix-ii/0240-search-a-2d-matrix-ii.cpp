class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        // Start from top-right of the matrix
        int row=0, col=n-1;

        while(row<m && col>=0){

            // If element found, return true
            if(matrix[row][col]==target)
                return true;

            // If target is smaller, then definately it will not be in that column, as columns are ascending. Hence we decrease the column by 1
            else if(matrix[row][col]>target)
                col--;

            // If target is bigger, then definately it will not be in that row, as rows are ascending. Hence we increase the row by 1
            else if(matrix[row][col]<target)
                row++;
        }
        return false;
    }
};