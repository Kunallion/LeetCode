//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int i, j, k, l, num=0;
        l = s.length();
        for(i=0 ; i<l ; i++)
        {
            if(s[i]=='I' && s[i+1]=='V')
            {
                num += 4;
                i++;
            }
            else if(s[i]=='I' && s[i+1]=='X')
            {
                num += 9;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='L')
            {
                num += 40;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='C')
            {
                num += 90;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='D')
            {
                num += 400;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='M')
            {
                num += 900;
                i++;
            }
            else if(s[i]=='I')
            {
                num += 1;
            }
            else if(s[i]=='V')
            {
                num += 5;
            }
            else if(s[i]=='X')
            {
                num += 10;
            }
            else if(s[i]=='L')
            {
                num += 50;
            }
            else if(s[i]=='C')
            {
                num += 100;
            }
            else if(s[i]=='D')
            {
                num += 500;
            }
            else if(s[i]=='M')
            {
                num += 1000;
            }
        }
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends