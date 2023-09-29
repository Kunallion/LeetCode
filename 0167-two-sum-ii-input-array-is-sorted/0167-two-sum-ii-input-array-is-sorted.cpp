class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i, j, low=0, high=numbers.size()-1, mid;
        vector<int> ans;
        for(i=0 ; i<numbers.size() ; i++)
        {
            j = target - numbers[i];
            low=i, high=numbers.size()-1;
            while(low<=high)
            {
                mid = (low+high)/2;
                if(numbers[mid]==j && mid!=i)
                {
                    ans.push_back(i+1);
                    ans.push_back(mid+1);
                    return ans;
                }
                else if(numbers[mid]<j)
                    low = mid+1;
                else if(numbers[mid]>j)
                    high = mid-1;
                else
                {
                    low++;
                    high++;
                }
            }
        }
        return ans;
    }
};