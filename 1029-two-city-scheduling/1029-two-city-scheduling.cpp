class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        // Storing the difference of costs for city A and B along with their index
        vector<pair<int, int>> arr;
        for(int i=0 ; i<costs.size() ; i++){
            arr.push_back({costs[i][0]-costs[i][1], i});
        }

        // Sort the arr
        sort(arr.begin(), arr.end());

        // first half of the array, we will take prices of A and for second half we will take the prices of B
        int ans=0;
        for(int i=0 ; i<arr.size() ; i++){
            if(i<arr.size()/2)
                ans += costs[arr[i].second][0];
            else
                ans += costs[arr[i].second][1];
        }

        return ans;
    }
};