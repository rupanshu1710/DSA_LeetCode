// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

vector<int> reaching_height(int n, int a[]) {

    sort(a,a+n);
    
    vector<int> ans(n);
    int i = 0;
    int j = n-1;
    int diff = 0;
    int m = 0;
    
    if(n == 1 && a[0] != 0)
        return {a[0]};
    
    while(i<=j){
        int x = a[j--];
        int y = a[i++];
        
        diff += x -y;
        
        if(diff<=0){
            return {-1};
        }
        
        ans[m++] = x;
        ans[m++] = y;
    }
    return ans;
}
