class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int res = INT_MAX;
       // int m = grid.length;
        //int n = grid[0].length; 
        int m = grid[0].size();
        int n = grid.size();
        int t[n][m];
        for(int j=0; j<m; j++){
            t[n-1][j] = grid[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<m; j++){
                int ans = INT_MAX;
                for(int k=0; k<m; k++){
                    ans = min(t[i+1][k]+moveCost[grid[i][j]][k],ans);
                }
                t[i][j] = grid[i][j]+ans;
            }
        }
        for(int j=0; j<m; j++){
            res = min(res,t[0][j]);
        }
        return res;
    }
};