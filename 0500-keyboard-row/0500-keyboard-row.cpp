class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        string s4 = "";
        vector<string> ans;
        int i, j, flag1, flag2, flag3;
        for(i=0 ; i<words.size() ; i++)
        {
            flag1=0, flag2=0, flag3=0;
            s4 = words[i];
            transform(s4.begin(), s4.end(), s4.begin(), ::tolower);
            for(j=0 ; j<words[i].size() ; j++)
            {
                if(flag1==0 && count(s1.begin(), s1.end(), s4[j])==0)
                {
                    flag1=1;
                }
                if(flag2==0 && count(s2.begin(), s2.end(), s4[j])==0)
                {
                    flag2=1;
                }
                if(flag3==0 && count(s3.begin(), s3.end(), s4[j])==0)
                {
                    flag3=1;
                }
                if(flag1==1 && flag2==1 && flag3==1)
                {
                    break;
                }
            }
            if(flag1==0 || flag2==0 || flag3==0)
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};