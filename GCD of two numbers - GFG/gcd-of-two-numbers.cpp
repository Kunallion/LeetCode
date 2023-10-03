//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    private:
    int solvegcd(int a, int b){
        
        if(b==0)
            return a;
        
        return gcd(b, a%b);
    }
	public:
    int gcd(int A, int B) 
	{ 
	    // code here
	    return solvegcd(A, B);
	      
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends