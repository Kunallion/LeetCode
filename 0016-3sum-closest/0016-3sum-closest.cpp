class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int i, j, k, closest, sum=0;
        closest = nums[0]+nums[1]+nums[3];

        sort(nums.begin(), nums.end());

        for(i=0 ; i<nums.size()-2 ; i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            j=i+1, k=nums.size()-1;
            while(j<k)
            {
                sum = nums[i]+nums[j]+nums[k];
    
                if(sum==target)
                    return target;
                if(abs(target-sum)<abs(target-closest))
                    closest = sum;
                else if(sum>target)
                    k--;
                else if(sum<target)
                    j++;
            }
        }
        return closest;
    }
};