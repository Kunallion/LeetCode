// class Solution {
// public:
//     int numTimesAllBlue(vector<int>& flips) {
        
//         string binaryStr = "";
//         for(int i=0 ; i<flips.size() ; i++){
//             binaryStr += '0';
//         }

//         int count=0;
//         for(int i=0 ; i<flips.size() ; i++){

//             binaryStr[flips[i]-1] = '1';
//             int j;
//             for(j=0 ; j<flips[i] ; j++){
//                 if(binaryStr[j]=='0')
//                     break;
//             }
//             // cout<<binaryStr<<endl;
//             if(j==flips[i]){
//                 int k;
//                 for(k=i+1 ; k<flips.size() ; k++){
//                     if(binaryStr[k]=='1')
//                         break;
//                 }
//                 if(k==flips.size())
//                     count++;
//             }
//         }

//         return count;
//     }
// };




class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        
        int rightmost=0, ans=0;

        for(int i=0 ; i<flips.size() ; i++){

            rightmost = max(rightmost, flips[i]);

            // if rightmost == (i+1), then it says that total total i bits are '1' and the rightmost is also i, then hence all the bits upto i are 1, hence that's a valid answer
            if(rightmost==i+1)
                ans++;
        }

        return ans;
    }
};