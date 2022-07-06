// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string,int> mp;
    int mod = 1003;
    int solve(string s, int i, int j, bool isTrue){
        if(i>j)return 0;
        if(i==j){
            if(isTrue)return s[i]=='T';
            else return s[i]=='F';
        }
        string temp = to_string(i);
        temp += ' ';
        temp += to_string(j);
        temp += ' ';
        temp += to_string(isTrue);
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        int ans=0;
        for(int k=i+1; k<j; k=k+2){
            int lf = solve(s,i,k-1,false);
            int lt = solve(s,i,k-1,true);
            int rf = solve(s,k+1,j,false);
            int rt = solve(s,k+1,j,true);
            if(s[k] == '|'){
                if(isTrue) ans += (lt*rt + lt*rf + lf*rt)%mod;
                else ans += (lf*rf)%mod;
            }
            else if(s[k] == '&'){
                if(isTrue) ans += (lt*rt)%mod;
                else ans += (lt*rf + lf*rt + lf*rf)%mod;
            }
            else if(s[k] == '^'){
                if(isTrue) ans += (lt*rf + lf*rt)%mod;
                else ans += (lf*rf + lt*rt)%mod;
            }
        }
        return mp[temp]=(ans)%mod;
    }
    int countWays(int n, string s){
        return solve(s,0,n-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends