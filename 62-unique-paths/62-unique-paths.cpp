class Solution {
public:
    int t[101][101];
    int solve(int m, int n, vector<vector<int>>& dp) {
        if(m<0 || n<0)return 0;
        if(m==0 && n==0)return 1;  
        if(dp[m][n])return dp[m][n];
        else return  dp[m][n] = solve(m-1, n, dp) + solve(m, n-1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        return solve(m-1,n-1,dp);
    }
};