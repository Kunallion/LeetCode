class Solution {
public:
    int minAddToMakeValid(string s) {

        int i=0;
        stack<char> st;

        for(i=0 ; i<s.length() ; i++)
        {
            if(st.empty()){
                st.push(s[i]);
            }
            else if(st.top()=='(' && s[i]==')')
            {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};