class Solution {
public:
    int t[20];
    int numTrees(int n){
        memset(t,0,sizeof(t));
        t[0] = 1;
        t[1] = 1;
        for(int i=2; i<n+1; i++){
            int ans=0;
            for(int j=1; j<=i; j++){
                ans += t[j-1]*t[i-j];
            }
            t[i] = ans;
        }
        return t[n];
    }
};