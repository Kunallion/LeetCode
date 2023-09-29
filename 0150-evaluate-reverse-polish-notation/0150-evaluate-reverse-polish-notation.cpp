class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int num1, num2;
        for(int i=0 ; i<tokens.size() ; i++)
        {
            if(tokens[i]=="+")
            {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                s.push(num2+num1);
            }
            else if(tokens[i]=="-")
            {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                s.push(num2-num1);
            }
            else if(tokens[i]=="*")
            {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                s.push(num2*num1);
            }
            else if(tokens[i]=="/")
            {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                s.push(num2/num1);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
            
        }
        return s.top();
    }
};