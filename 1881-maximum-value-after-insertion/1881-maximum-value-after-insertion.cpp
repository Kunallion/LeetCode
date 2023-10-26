class Solution {
public:
    string maxValue(string n, int x) {
        
        int i;
        string s = to_string(x);
        char c = s[0];

        if(n[0]=='-'){

            // For Negative numbers, we check from index 1 as index 0 contains '-' sign
            for(i=1 ; i<n.length() ; i++){
                if((n[i]-48)>x){
                    n.insert(n.begin()+i, c);
                    return n;
                }
            }
            n.insert(n.begin()+i, c);
            return n;
        }
        else{

            // For positive numbers we check from 0 index as no sign is there
            for(i=0 ; i<n.length() ; i++){
                if((n[i]-48)<x){
                    n.insert(n.begin()+i, c);
                    return n;
                }
            }
            n.insert(n.begin()+i, c);
            return n;
        }
        return n;
    }
};