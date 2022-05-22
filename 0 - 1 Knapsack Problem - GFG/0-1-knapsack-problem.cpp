// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int t[1001][1001];
    int knap(int w, int wt[], int val[], int n) 
    { 
       if(n==0  || w==0)return 0;
       if(t[n][w]!=-1)return t[n][w];
       if(wt[n-1]<=w)return t[n][w] = max(val[n-1]+knap(w-wt[n-1],wt,val,n-1),knap(w,wt,val,n-1));
       else return t[n][w] = knap(w,wt,val,n-1);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    {
        memset(t,-1,sizeof(t));
        knap(w,wt,val,n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends