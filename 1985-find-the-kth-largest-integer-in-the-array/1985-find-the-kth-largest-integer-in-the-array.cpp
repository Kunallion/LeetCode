class Solution {
public:
    // Custom Comparator
    static bool cmp(string& s1, string& s2){
        // If same length, then just return true if s1 is lexigraphically smaller than s2
        if(s1.length()==s2.length())
            return s1<s2;

        // If different lengths, then return true is the length of s1 is less than s2
        return s1.length()<s2.length();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        
        // Sort using custom comparotor
        sort(nums.begin(), nums.end(), cmp);
        return nums[nums.size()-k];
    }
};