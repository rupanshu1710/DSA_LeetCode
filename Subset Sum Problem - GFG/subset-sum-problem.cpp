// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int t[101][10001];
    Solution(){
       memset(t, -1, sizeof(t));
   }
    bool isSubset(vector<int>&arr, int sum,int n)
    {
        if(t[n][sum]!=-1)return t[n][sum];
        if(sum==0) return 1;
        if(n<=0 || sum<0)  return 0;
        
        if(arr[n-1]<=sum)
        {
            t[n][sum] =  isSubset(arr,sum-arr[n-1],n-1) || isSubset(arr,sum,n-1);
        }
        else
        {
            t[n][sum] =  isSubset(arr,sum,n-1);
        }
        return t[n][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n = int(arr.size());
        return isSubset(arr,sum,n);
    
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends