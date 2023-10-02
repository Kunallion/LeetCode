class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l, w;
        vector<int> ans;
        w = sqrt(area);
        l = sqrt(area);
        while(true)
        {
            if(l*w==area)
            {
                ans.push_back(l);
                ans.push_back(w);
                break;
            }
            else if(l*w<area)
            {
                l++;
            }
            else if(l*w>area)
            {
                w--;
            }
        }
        return ans;
    }
};