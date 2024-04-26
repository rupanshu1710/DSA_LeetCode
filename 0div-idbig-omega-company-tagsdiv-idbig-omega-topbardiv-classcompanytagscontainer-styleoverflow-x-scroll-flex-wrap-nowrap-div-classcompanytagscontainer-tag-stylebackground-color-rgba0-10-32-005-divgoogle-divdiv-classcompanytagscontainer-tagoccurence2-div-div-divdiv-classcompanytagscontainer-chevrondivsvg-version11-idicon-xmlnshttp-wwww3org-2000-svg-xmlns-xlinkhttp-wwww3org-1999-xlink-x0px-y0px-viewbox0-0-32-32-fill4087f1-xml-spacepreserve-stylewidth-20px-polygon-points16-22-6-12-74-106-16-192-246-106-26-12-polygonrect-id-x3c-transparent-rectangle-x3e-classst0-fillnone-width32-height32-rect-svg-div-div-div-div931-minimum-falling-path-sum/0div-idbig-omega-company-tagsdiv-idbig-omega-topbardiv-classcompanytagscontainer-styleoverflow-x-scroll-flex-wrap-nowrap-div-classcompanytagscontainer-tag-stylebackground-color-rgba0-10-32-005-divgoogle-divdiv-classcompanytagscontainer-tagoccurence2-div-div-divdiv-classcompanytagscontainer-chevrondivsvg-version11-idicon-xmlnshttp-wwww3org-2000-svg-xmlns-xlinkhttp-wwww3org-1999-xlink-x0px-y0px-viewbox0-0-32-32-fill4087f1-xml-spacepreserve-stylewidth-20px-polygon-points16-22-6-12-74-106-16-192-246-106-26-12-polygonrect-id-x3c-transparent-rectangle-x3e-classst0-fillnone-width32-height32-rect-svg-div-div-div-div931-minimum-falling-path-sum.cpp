class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0] = matrix[0];
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(j==0){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==m-1){
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
                else dp[i][j] = matrix[i][j] + min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
            }
        }
        ans = *min_element(dp[n-1].begin(),dp[n-1].end());
        return ans;
    }
};