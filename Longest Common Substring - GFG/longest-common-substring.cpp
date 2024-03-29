// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        
        return getAns(s1,s2,n,m);
    }
    int getAns(string &text1, string &text2, int n1, int n2){
        int t[n1+1][n2+1];
        int ans=0;
        for(int i=0; i<n1+1; i++){
            for(int j=0; j<n2+1; j++){
                if(i==0 || j==0)t[i][j]=0;
            }
        }
        for(int i=1; i<n1+1; i++){
            for(int j=1; j<n2+1; j++){
                if(text1[i-1]==text2[j-1]) t[i][j] = 1+t[i-1][j-1];
                else t[i][j] = 0;
                ans = max(ans,t[i][j]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends