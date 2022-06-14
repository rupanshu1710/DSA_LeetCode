// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n) {
            
            int ans = 0;
            int l = 1, h = 2 * n;
            while(l < h) {
                int m = l + (h - l) / 2;
                
                int val = 5 * m;
                int cnt = 0;
                for(long long i = 5; i <= 5 * n; i *= 5)
                    cnt += val / i;
                    
                if(cnt >= n) {
                    ans = m;
                    h = m;
                }
                else l = m + 1;
            }
            return ans * 5;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends