class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        vector<string> temp;
        int i;
        for(i=1 ; i<=n ; i++)
            temp.push_back(to_string(i));

        sort(temp.begin(), temp.end());

        for(i=0 ; i<n ; i++)
            ans.push_back(stoi(temp[i]));
        
        return ans;
    }
};