class Solution {
public:
    int trap(vector<int>& height) {
        int i, ans=0, n=height.size();
        int leftmax=-1, rightmax=-1;
        int left[n];
        int right[n];

        for(i=0 ; i<n ; i++)
        {
            if(height[i]>leftmax)
            {
                leftmax = height[i];
            }
            left[i] = leftmax;
        }
        for(i=n-1 ; i>=0 ; i--)
        {
            if(height[i]>rightmax)
            {
                rightmax = height[i];
            }
            right[i] = rightmax;
        }
        for(i=0 ; i<n ; i++)
        {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};