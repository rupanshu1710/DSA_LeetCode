// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int countSubsetSum(int nums[], int n, int targetSum)
    {
        long long int m =(1e9+7);
        long long int t[n+1][targetSum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<targetSum+1; j++){
                if(!i)t[i][j]=0;
                if(!j)t[i][j]=1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j<targetSum+1; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]]%m + t[i-1][j]%m;
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][targetSum]%m;
    }
    int perfectSum(int nums[], int n, int sum)
	{
        return countSubsetSum(nums,n,sum);
	}
};
// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends