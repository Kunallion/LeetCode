class Solution {
public:
    int nextGreaterElement(int n) {
        
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        auto ans = stoll(s); // string to long long

        // We need to check whether ans is greater than INT_MAX, if yes, then return -1, as we want pur ans in INT range
        if(ans>INT_MAX || ans<=n)
            return -1;
        return ans;
    }
};