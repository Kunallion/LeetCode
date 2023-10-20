class Solution {
private:
    void solve(vector<vector<int>>& graph, int src, int dest, vector<int> temp, vector<vector<int>>& ans){

        // Base Case
        if(src==dest){
            temp.push_back(src);
            ans.push_back(temp);
            temp.clear();
            return;
        }

        temp.push_back(src);
        for(int i=0 ; i<graph[src].size() ; i++){
            solve(graph, graph[src][i], dest, temp, ans);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        int n = graph.size();
        solve(graph, 0, n-1, temp, ans);

        return ans;
    }
};