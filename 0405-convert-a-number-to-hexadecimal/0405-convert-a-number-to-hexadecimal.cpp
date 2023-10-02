class Solution {
public:
    string toHex(int num) {
        if(num==0)
            return "0";
        u_int num1 = num;
        string s="";
        while(num1)
        {
            int temp = num1%16;
            if(temp<=9)
                s += to_string(temp);
            else
                s += 87+temp;
            num1 /= 16;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};