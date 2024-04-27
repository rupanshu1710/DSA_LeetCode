class Solution {
public:
    // int dp[101][101];
    // int solve(int ridx, int kidx, string ring, string key){
    //     if(kidx>=key.size())return 0;
    //     if(dp[ridx][kidx]!=-1)return dp[ridx][kidx];
    //     int ans = INT_MAX;
    //     for(int i=0; i<ring.size(); i++){
    //         if(ring[i]==key[kidx]){
    //             int steps = 1 + min(abs(i-ridx),(int)ring.size()-abs(i-ridx));
    //             int totalSteps = steps + solve(i,kidx+1,ring,key);
    //             ans = min(ans,totalSteps);
    //         }
    //     }
    //     return dp[ridx][kidx] = ans;
    // }
    int findRotateSteps(string ring, string key) {
        // memset(dp,-1,sizeof(dp));
        // vector<int>temp(26,INT_MAX);
        // for(int i=0; i<n; i++){
        //     temp[]
        // }
        int n = ring.size();
        int m = key.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        for(int i=0; i<n; i++){
            dp[i][m] = 0;
        }
        for(int kidx=m-1; kidx>=0; kidx--){
            for(int ridx=0; ridx<n; ridx++){
                int ans = INT_MAX;
                for(int i=0; i<n; i++){
                    if(ring[i]==key[kidx]){
                        int steps = 1 + min(abs(i-ridx),n-abs(i-ridx));
                        int totalSteps = steps + dp[i][kidx+1];
                        ans = min(ans,totalSteps);
                    }
                }
                dp[ridx][kidx] = ans;
            }
        }
        return dp[0][0];
    }
};