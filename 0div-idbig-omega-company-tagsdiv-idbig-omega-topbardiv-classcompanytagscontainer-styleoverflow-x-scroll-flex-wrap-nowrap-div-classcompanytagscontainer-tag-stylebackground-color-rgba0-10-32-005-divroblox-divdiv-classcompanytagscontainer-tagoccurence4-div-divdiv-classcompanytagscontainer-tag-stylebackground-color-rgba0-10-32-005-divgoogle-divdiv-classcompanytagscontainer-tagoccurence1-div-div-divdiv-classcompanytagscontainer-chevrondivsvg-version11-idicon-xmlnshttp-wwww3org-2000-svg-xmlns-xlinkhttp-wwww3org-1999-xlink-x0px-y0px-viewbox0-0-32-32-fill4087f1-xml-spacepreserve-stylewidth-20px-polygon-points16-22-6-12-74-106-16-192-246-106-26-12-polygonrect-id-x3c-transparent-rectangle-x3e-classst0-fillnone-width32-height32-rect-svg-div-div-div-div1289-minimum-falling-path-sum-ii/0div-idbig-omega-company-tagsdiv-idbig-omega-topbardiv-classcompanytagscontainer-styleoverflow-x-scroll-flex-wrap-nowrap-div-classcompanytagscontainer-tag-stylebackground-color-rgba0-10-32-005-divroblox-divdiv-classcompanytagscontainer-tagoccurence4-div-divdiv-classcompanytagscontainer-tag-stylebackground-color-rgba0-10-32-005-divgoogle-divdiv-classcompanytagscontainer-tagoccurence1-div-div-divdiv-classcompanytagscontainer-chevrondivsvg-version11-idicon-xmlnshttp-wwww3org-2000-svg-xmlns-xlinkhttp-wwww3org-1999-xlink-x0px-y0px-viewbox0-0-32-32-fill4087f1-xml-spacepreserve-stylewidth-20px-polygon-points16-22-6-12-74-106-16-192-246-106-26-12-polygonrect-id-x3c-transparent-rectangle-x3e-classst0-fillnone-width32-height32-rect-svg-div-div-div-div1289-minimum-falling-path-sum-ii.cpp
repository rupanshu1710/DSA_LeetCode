class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        dp[0] = matrix[0];
        vector<int>temp = matrix[0];
        sort(temp.begin(),temp.end());
        int mn1 = temp[0];
        int mn2 = temp[1];
        for(int i=1; i<n; i++){
            int x=INT_MAX;
            int y=INT_MAX;
            for(int j=0; j<n; j++){
                if(dp[i-1][j]==mn1){
                    dp[i][j] = matrix[i][j] + mn2;
                }
                else dp[i][j] = matrix[i][j] + mn1;
                if(dp[i][j]<=x){
                    y = x;
                    x = dp[i][j];
                }
                else if(dp[i][j]>x && dp[i][j]<y){
                    y = dp[i][j];
                }
            }
            mn1 = x;
            mn2 = y;
        }
        ans = *min_element(dp[n-1].begin(),dp[n-1].end());
        return ans;
    }
};