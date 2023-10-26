class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        
        int i, j, k=0, l, flag=0;
        for(i=0 ; i<nums.size() ; i++){
            k=0;
            if(nums[i]==groups[k][0]){
                l=i;
                while(l<nums.size() && k<groups.size()){
                    flag=0;
                    for(j=0 ; j<groups[k].size() ; j++){
                        if(nums[l]!=groups[k][j]){
                            flag=1;
                            break;
                        }
                        else{
                            l++;
                        }
                    }
                    if(flag==1){
                        l++;
                    }
                    if(j==groups[k].size()){
                        k++;
                    }
                }
                if(k==groups.size())
                    return true;
            }
        }
        return false;
    }
};