class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int ans=0, flag=0;

        for(int i=0 ; i<dig.size() ; i++){
            arr[dig[i][0]][dig[i][1]] = 1;
        }

        for(int i=0 ; i<artifacts.size() ; i++){
            for(int j=artifacts[i][0] ; j<=artifacts[i][2] ; j++){
                for(int k=artifacts[i][1] ; k<=artifacts[i][3] ; k++){
                    if(arr[j][k]!=1){
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
            if(flag==0)
                ans++;
            else
                flag=0;
        }

        return ans;
    }
};