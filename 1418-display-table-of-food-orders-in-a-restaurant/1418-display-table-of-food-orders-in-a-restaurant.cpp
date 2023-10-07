class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        map<int, map<string, int>> mp;
        set<string> s;

        for(int i=0 ; i<orders.size() ; i++){
            s.insert(orders[i][2]);
            mp[stoi(orders[i][1])][orders[i][2]]++;
        }
        
        vector<vector<string>> ans;
        vector<string> temp;
        temp.push_back("Table");

        for(auto it:s){
            temp.push_back(it);
        }
        ans.push_back(temp);
        temp.clear();


        for(auto it:mp){
            temp.push_back(to_string(it.first));
            for(int i=1 ; i<ans[0].size() ; i++){
                if(mp[it.first].find(ans[0][i])!=mp[it.first].end())
                    temp.push_back(to_string(mp[it.first][ans[0][i]]));
                else
                    temp.push_back("0");
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};