class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        unordered_map<int, vector<int>> mp;
        for(int i=0 ; i<cards.size() ; i++){
            mp[cards[i]].push_back(i);
        }

        int ans=INT_MAX;
        for(auto it:mp){
            if(it.second.size()>1){
                int mini = INT_MAX;
                for(int i=0 ; i<it.second.size()-1 ; i++){
                    mini = min(mini, it.second[i+1]-it.second[i]);
                }
                ans = min(ans, mini);
            }
        }
        if(ans==INT_MAX)
            return -1;
        return ans+1;
    }
};