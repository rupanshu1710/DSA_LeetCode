// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n){
	    long long totalSum = 0,ans=INT_MAX;
        for(auto i=0; i<n; i++){
            totalSum += arr[i];
        }
        vector<int>res;
	    long long int t[n+1][totalSum+1];
	    for(int i=0; i<n+1; i++){
	        for(int j=0; j<totalSum+1; j++){
	            if(!i){
	                t[i][j]=0;
	            }
	            if(!j){
	                t[i][j]=1;
	            }
	        }
	    }
	    for(int i=1; i<n+1; i++){
	        for(int j=1; j<totalSum+1; j++){
	            if(arr[i-1]<=j){
	                t[i][j] = t[i-1][j-arr[i-1]] or t[i-1][j];
	            }
	            else{
	                t[i][j] =  t[i-1][j];
	            }
	        }
	    }
	    for(int j=0;j<=totalSum;j++)
      {
          if(t[n][j])
          {
              ans=min(ans,abs(totalSum-2*j));
          }
      }
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends