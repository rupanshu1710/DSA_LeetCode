// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int n1, int n2)
    {
        int t[n1+1][n2+1];
        for(int i=0; i<n1+1; i++){
            for(int j=0; j<n2+1; j++){
                if(i==0 || j==0)t[i][j]=0;
            }
        }
        for(int i=1; i<n1+1; i++){
            for(int j=1; j<n2+1; j++){
                if(s1[i-1]==s2[j-1])t[i][j]=1+t[i-1][j-1];
                else{
                    t[i][j] = max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return n1 + n2 - t[n1][n2];
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends