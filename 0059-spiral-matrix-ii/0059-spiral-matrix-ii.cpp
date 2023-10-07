class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        
        int strtRow=0;
        int endRow=n-1;
        int strtCol=0;
        int endCol=n-1;
        int tot=n*n;
        int cnt=0;
        int k=1;

        while(cnt<tot){
            //Left se right filling
            for(int i=strtCol;i<=endCol && cnt<tot && k<=tot;i++){
                //temp.push_back(arr[strtRow][i]);
                arr[strtRow][i]=k;
                k++;
                cnt++;
            }
            strtRow++;

            //Top to bottom filling
            for(int i=strtRow;i<=endRow && cnt<tot && k<=tot;i++){
                //temp.push_back(arr[i][endCol]);
                arr[i][endCol]=k;
                k++;
                cnt++;
            }
            endCol--;

            //Right se Left filling
            for(int i=endCol;i>=strtCol && cnt<tot && k<=tot;i--){
                //temp.push_back(arr[endRow][i]);
                arr[endRow][i]=k;
                k++;
                cnt++;
            }
            endRow--;

            //Bottom se Top filling
            for(int i=endRow;i>=strtRow && cnt<tot && k<=tot;i--){
                //temp.push_back(arr[i][strtCol]);
                arr[i][strtCol]=k;
                k++;
                cnt++;
            }
            strtCol++;
        }

        return arr;
    }
};