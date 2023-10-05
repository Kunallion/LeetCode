class Solution {
public:
    long long smallestNumber(long long num) {
        
        if(num==0)
            return num;
        
        // Convert the num to string
        string s = to_string(num);

        // if num is negative, then sort the string in descending order
        if(num<0){
            sort(s.begin(), s.end(), greater<int>());

            // Convert the string to long long and multiply by (-1) as it is negative
            return (-1LL)*stoll(s);
        }

        // If the number is positive, sort it in ascending order
        else
            sort(s.begin(), s.end());
        
        // If the string contains leading 0's, then we need to find the first non-zero int and swap its position with the first index, so that the leading int is not zero
        int i=0;
        while(s[i]=='0'){
            i++;
        }
        swap(s[i], s[0]);

        return stoll(s);
    }
};