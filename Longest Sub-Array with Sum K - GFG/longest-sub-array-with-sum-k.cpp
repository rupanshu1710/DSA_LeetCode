//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
       long long currSum =0;
       int i=0,ans = 0; 
       
       map<long long, int>mp;
       for(int i=0; i<n; i++){
           currSum += a[i];
        //   cout<<currSum<<endl;
           if(mp.find(currSum-k)!=mp.end()){
               ans = max(ans,i-mp[currSum-k]);
           }
           if(currSum==k){
               ans = max(ans,i+1);
           }
           if(mp.find(currSum)==mp.end())mp[currSum] = i;
       }
       return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends