class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int arr_sum = accumulate(nums.begin(), nums.end(), 0);
        int sum_of_n_nums = n*(n+1)/2;
        return sum_of_n_nums - arr_sum;
    }
};