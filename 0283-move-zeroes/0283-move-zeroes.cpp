// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int i=0, n;
//         n = nums.size();
//         while(n--)
//         {
//             if(nums[i]==0)
//             {
//                 nums.erase(nums.begin()+i);
//                 nums.push_back(0);
//             }
//             else
//             {
//                 i++;
//             }
//         }
//     }
// };




class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, index=0;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i], nums[index]);
                index++;
            }
        }
    }
};