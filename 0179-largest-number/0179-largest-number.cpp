class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        // Making an array to store the strings
        vector<string> arr;
        for(int i=0 ; i<nums.size() ; i++)
            arr.push_back(to_string(nums[i]));


        // Sorting the array on the basis of s1+s2>s2+s1
        sort(arr.begin(), arr.end(),[](string& s1, string& s2){return s1+s2>s2+s1;});

        string ans="";
        for(int i=0 ; i<arr.size() ; i++)
            ans += arr[i];
        

        // To remove the 0's at front of the number
        while(ans[0]=='0' && ans.length()>1)
            ans.erase(ans.begin()+0);
        
        return ans;
    }
};