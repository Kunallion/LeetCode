class Solution {
public:
    void func(int open, int close, string temp, vector<string> &ans, int n)
    {
        if(temp.size()==2*n){
            ans.push_back(temp);
            return;
        }

        if(open<n)
            func(open+1, close, temp+'(', ans, n);

        if(close<open)
            func(open, close+1, temp+')', ans, n);
    }
    vector<string> generateParenthesis(int n) {

        string temp="";
        vector<string> ans;
        func(0, 0, temp, ans, n);
        return ans;
    }
};