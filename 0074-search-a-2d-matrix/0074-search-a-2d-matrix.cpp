class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;
        int i, j;
        for(i=0 ; i<matrix.size() ; i++)
        {
            for(j=0 ; j<matrix[0].size() ; j++)
            {
                arr.push_back(matrix[i][j]);
            }
        }
        int low=0, high = arr.size()-1, mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(arr[mid]==target)
                return true;
            else if(arr[mid]>target)
                high = mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};