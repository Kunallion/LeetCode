class Solution {
public:
    void solve(string &digits, vector<string>& ans, string str, int index, string mapping[])
    {
        if(index>=digits.size())
        {
            ans.push_back(str);
            return;
        }

        int number = digits[index] - '0';
        string values = mapping[number];

        for(int i=0 ; i<values.size() ; i++)
        {
            str.push_back(values[i]);
            solve(digits, ans, str, index+1, mapping);

            // Backtracking
            str.pop_back(); 
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string str="";
        if(digits.length()==0)
            return ans;
        
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        int index=0;
        solve(digits, ans, str, index, mapping);

        return ans;
    }
};