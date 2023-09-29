class Solution {
public:
    string reverseWords(string s) {
        int i;
        string temp="";
        vector<string> arr;
        string ans = "";
        for(i=0 ; i<s.length() ; i++)
        {
            if(s[i]!=' ')
            {
                temp += s[i];
            }
            else if(s[i]==' ' && temp.length()>0)
            {
                arr.push_back(temp);
                temp.clear();
            }
        }
        if(temp.length()>0)
        {
            arr.push_back(temp);
            temp.clear();
        }
        reverse(arr.begin(), arr.end());
        for(i=0 ; i<arr.size()-1 ; i++)
        {
            ans += arr[i];
            ans += ' ';
        }
        ans += arr[arr.size()-1];
        return ans;
    }
};