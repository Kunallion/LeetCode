class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        string ans="";
        string temp="";
        int flag=0;

        unordered_map<string, string> mp;

        for(int i=0 ; i<knowledge.size() ; i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        for(int i=0 ; i<s.length() ; i++){

            if(flag==0 && s[i]=='(')
                flag=1;
            
            else if(flag==1 && s[i]!=')')
                temp += s[i];
            
            else if(flag==1 && s[i]==')'){
                flag=0;
                if(mp.find(temp)!=mp.end())
                    ans += mp[temp];
                else
                    ans += '?';
                temp.clear();
            }
            else
                ans += s[i];
        }
        return ans;
    }
};