class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        
        int maxlen=-1, len, flag;
        for(int i=0 ; i<nums.size() ; i++){
            flag=-1;
            len=0;
            for(int j=i ; j<nums.size()-1 ; j++){
                if(nums[j+1]-nums[j]==1 && (flag==-1 || flag==0)){
                    len++;
                    flag=1;
                }
                else if(nums[j+1]-nums[j]==-1 && flag==1){
                    len++;
                    flag=0;
                }
                else
                    break; 
            }
            if(len!=0)
                maxlen = max(maxlen, len+1);
        }
        return maxlen;
    }
};