class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i, j, k, next_greater_element=-1;

        for(i=0 ; i<nums1.size() ; i++)
        {
            next_greater_element = -1;
            for(j=0 ; j<nums2.size() ; j++)
            {
                if(nums1[i]==nums2[j])
                {
                    for(k=j+1 ; k<nums2.size() ; k++)
                    {
                        if(nums1[i]<nums2[k])
                        {
                            next_greater_element = nums2[k];
                            break;
                        }
                    }
                    ans.push_back(next_greater_element);
                }
            }
        }
        return ans;
    }
};