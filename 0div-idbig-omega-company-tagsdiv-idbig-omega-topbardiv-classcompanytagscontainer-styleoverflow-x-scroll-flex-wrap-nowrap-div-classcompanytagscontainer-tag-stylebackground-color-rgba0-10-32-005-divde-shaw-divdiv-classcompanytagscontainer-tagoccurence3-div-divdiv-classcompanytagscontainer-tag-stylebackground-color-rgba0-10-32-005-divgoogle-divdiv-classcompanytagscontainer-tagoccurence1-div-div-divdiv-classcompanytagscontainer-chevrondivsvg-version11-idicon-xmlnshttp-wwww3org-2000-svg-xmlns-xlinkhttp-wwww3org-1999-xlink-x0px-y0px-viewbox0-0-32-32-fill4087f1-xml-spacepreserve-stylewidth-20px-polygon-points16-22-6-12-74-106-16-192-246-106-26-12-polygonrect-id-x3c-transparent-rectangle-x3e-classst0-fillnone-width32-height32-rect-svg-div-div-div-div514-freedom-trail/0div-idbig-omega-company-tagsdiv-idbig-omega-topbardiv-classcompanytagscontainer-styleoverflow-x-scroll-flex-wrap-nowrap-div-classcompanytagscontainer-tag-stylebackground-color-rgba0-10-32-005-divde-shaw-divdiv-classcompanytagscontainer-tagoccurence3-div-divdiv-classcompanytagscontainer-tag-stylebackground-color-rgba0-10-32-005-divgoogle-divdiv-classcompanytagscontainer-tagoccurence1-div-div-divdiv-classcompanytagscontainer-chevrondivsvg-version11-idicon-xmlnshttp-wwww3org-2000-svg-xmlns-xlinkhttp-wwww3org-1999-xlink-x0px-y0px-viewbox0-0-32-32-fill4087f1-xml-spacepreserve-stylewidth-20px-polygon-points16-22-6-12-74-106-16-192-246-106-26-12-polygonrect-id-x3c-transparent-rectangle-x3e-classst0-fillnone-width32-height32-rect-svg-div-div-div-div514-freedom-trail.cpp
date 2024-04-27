class Solution {
public:
    int dp[101][101];
    int solve(int ridx, int kidx, string ring, string key){
        if(kidx>=key.size())return 0;
        int ans = INT_MAX;
        if(dp[ridx][kidx]!=-1)return dp[ridx][kidx];
        for(int i=0; i<ring.size(); i++){
            if(ring[i]==key[kidx]){
                int steps = 1 + min(abs(i-ridx),(int)ring.size()-abs(i-ridx));
                int totalSteps = steps + solve(i,kidx+1,ring,key);
                ans = min(ans,totalSteps);
            }
        }
        return dp[ridx][kidx] = ans;
    }
    int findRotateSteps(string ring, string key) {
        memset(dp,-1,sizeof(dp));
        // vector<int>temp(26,INT_MAX);
        // for(int i=0; i<n; i++){
        //     temp[]
        // }
        return solve(0,0,ring,key);
    }
};