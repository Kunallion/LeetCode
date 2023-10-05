class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int ans=0;
        vector<vector<int>> arr;
        
        // Store the max value of each row as all element of the row
        for(int i=0 ; i<grid.size() ; i++){
            int maxi = 0;

            // Finding row maximum
            for(int j=0 ; j<grid[0].size() ; j++){
                maxi = max(maxi, grid[i][j]);
            }
            vector<int> temp(grid[0].size(), maxi);
            arr.push_back(temp);
        }

        // Now update the value of arr as minimum of the row maximum and the column maximum
        for(int i=0 ; i<grid[0].size() ; i++){
            int maxi = 0;

            // Finding Column Maximum
            for(int j=0 ; j<grid.size() ; j++){
                maxi = max(maxi, grid[j][i]);
            }

            // Updating elements as min of row maximum and col maximum
            for(int k=0 ; k<grid.size() ; k++){
                arr[k][i] = min(arr[k][i], maxi);
            }
        }

        // Add the differences of the arr matrix and grid matrix
        for(int i=0 ; i<arr.size() ; i++){
            for(int j=0 ; j<arr[0].size() ; j++){
                ans += arr[i][j]-grid[i][j];
            }
        }

        // Return ans
        return ans;
    }
};