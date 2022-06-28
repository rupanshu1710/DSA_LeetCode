// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
    {
        // Your code goes here
        priority_queue<int>maxh1;
        priority_queue<int>maxh2;
        for(int i=0; i<n; i++){
            maxh1.push(a[i]);
            maxh2.push(a[i]);
            if(maxh1.size()>k1)maxh1.pop();
            if(maxh2.size()>k2-1)maxh2.pop();
        }
        int ans = 0;
        while(maxh2.size()>0){
            ans += maxh2.top();
            maxh2.pop();
        }
        while(maxh1.size()>0){
            ans -= maxh1.top();
            maxh1.pop();
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends