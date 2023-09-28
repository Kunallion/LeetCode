class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, j, k;
        if(digits[digits.size()-1]+1<=9)
        {
            digits[digits.size()-1] += 1;
            return digits;
        }
        else
        {
            for(i=digits.size()-1 ; i>=0 ; i--)
            {
                if(digits[i]+1>9)
                {
                    digits[i] = 0;
                }
                else if(digits[i]+1<=9)
                {
                    digits[i] += 1;
                    break;
                }
            }
            if(digits[0]==0)
            {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};