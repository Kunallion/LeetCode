class Solution {
public:
    string decodeString(string s) {
        
        string ans = "";
        string temp1 = "";
        stack<string> st;

        for(int i=0 ; i<s.length() ; i++){

            // If the s[i]==']', then we will have to pop from stack and do some manipulations
            if(s[i]==']'){
                string temp2 = "";
                while(st.top()!="["){
                    st.top() += temp2;
                    temp2 = st.top();
                    st.pop();
                }
                st.pop();

                // Finding the integer by which we have to mutiply, example 3[a] means aaa
                string times="";
                while(!st.empty() && (isdigit(st.top()[0]))){
                    times += st.top();
                    st.pop();
                }
                reverse(times.begin(), times.end());


                // adding the subsstring to itself "times" times
                for(int j=0 ; j<stoi(times) ; j++){
                    temp1 += temp2;
                }

                // Pushing the new substring back in the stack and clearing the temp strings
                st.push(temp1);
                temp1.clear();
                temp2.clear();
            }

            // else just push in the stack as a string
            else{       

                // s[i] is char, so to convert to string we add the char to an empty string
                string str = "";
                str += s[i];
                st.push(str);
            }
        }

        // Now we just need to add up the substrings remaining in the stack to form our ans
        while(!st.empty()){
            st.top() += ans;
            ans = st.top();
            st.pop();
        }

        // return ans which is our decoded string
        return ans;
    }
};