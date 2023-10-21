class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        // Map stores content as key and all the filepaths which have same content as key
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        int flag=0;
        string filename="", content="", root="";

        for(int i=0 ; i<paths.size() ; i++){
            root="", flag=0;
            for(int j=0 ; j<paths[i].length() ; j++){

                // Root Name Building
                if(paths[i][j]!=' ' && flag==0){
                    root += paths[i][j];
                }
                else if(paths[i][j]==' '){
                    flag=1;
                }

                // Content Building
                else if(paths[i][j]=='('){
                    j++;
                    while(paths[i][j]!=')'){
                        content += paths[i][j];
                        j++;
                    }
                    filename = root+'/'+filename;
                    mp[content].push_back(filename);
                    filename.clear();
                    content.clear();

                    if(j==paths[i].length()-1)
                        break;            
                }

                // FileName Building
                else{
                    filename += paths[i][j];
                }
            }
        }

        // If a content appeared in more than 1 file, then all the filepaths with the content  is our ans
        for(auto it:mp){
            if(it.second.size()>1){
                ans.push_back(it.second);
            }
        }

        // Return ans
        return ans;
    }
};