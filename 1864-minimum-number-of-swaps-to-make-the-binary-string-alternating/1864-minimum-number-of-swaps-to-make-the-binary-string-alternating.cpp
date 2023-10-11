class Solution {
public:
    int minSwaps(string s) {
        
        // Count the number of zeros and ones in the string
        int ones, zeros, missingZeros=0, missingOnes=0;
        zeros = count(s.begin(), s.end(), '0');
        ones = s.length()-zeros;

        // If the difference between the number of ones and zeros is greater than 1, then definately the ans is -1 as it is not possible to swap them to make string alternating
        if(abs(zeros-ones)>1)
            return -1;
        
        // Traverse alternating chars
        for(int i=0 ; i<s.size() ; i += 2){
            
            if(s[i]!='0')
                missingZeros++;
            
            if(s[i]!='1')
                missingOnes++;
        }

        if(zeros==ones)
            return min(missingZeros, missingOnes);
        
        else if(zeros>ones)
            return missingZeros;

        return missingOnes;
    }
};