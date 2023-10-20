class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        if(arr.size()<3)
            return 0;
        
        int i=1, len=1, ans=0, flag=0;
        
        for(int i=1 ; i<arr.size() ; i++){
            if((arr[i]>arr[i-1] && flag==0) || (arr[i]<arr[i-1] && flag==1))
                len++;
            else if(arr[i]<arr[i-1] && flag==0 && len>1){
                len++;
                flag=1;
            }
            else if(arr[i]>arr[i-1] && flag==1){
                ans = max(ans, len);
                len=1;
                flag=0;
                i--;
            }
            else if(arr[i]==arr[i-1]){
                
                if(flag==1)
                    ans = max(ans, len);

                len=1;
                flag=0;
            }
        }
        if(flag==1)
            ans = max(ans, len);
        return ans;
    }
};