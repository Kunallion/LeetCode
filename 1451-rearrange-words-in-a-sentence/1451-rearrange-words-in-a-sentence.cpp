class Solution {
public:
    string arrangeWords(string text) {
        
        // Using Ordered_map beacuse we need to store the strings on the basis of their lengths in the increasing order
        map<int, vector<string>> mp;

        string str = "";
        string ans = "";
        int flag=0;

        // Extracting words from strings and storing in the map along with their their lengths
        for(int i=0 ; i<text.length() ; i++){

            if(text[i]!=' '){
                flag=1;
                str += text[i];
            }
            else if(text[i]==' ' && flag==1){
                flag=0;
                // Converting first letter to small if it's already not
                if(str[0]<97)
                    str[0] += 32;

                mp[str.length()].push_back(str);
                str.clear();
            }
        }
        if(flag==1){
            if(str[0]<97)
                str[0] += 32;
            mp[str.length()].push_back(str);
        }

        // Forming ans string
        for(auto it:mp){
            for(auto jt:mp[it.first]){
                ans += jt;
                ans += ' ';
            }
        }

        // Converting first char to Uppercase
        ans[0] -= 32;

        // Resizing the ans string, because we don't want the extra ' ' at the end of string
        ans.resize(ans.length()-1);
        return ans;
    }
};