//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int firstIndex(int a[], int n){
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(a[mid]==1){
                high=mid-1;
                // cout<<2<<endl;
                ans=mid;
            }
            else low = mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        cout << ob.firstIndex(a, n) << endl;
    }
}
// } Driver Code Ends