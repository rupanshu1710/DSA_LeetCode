class Solution {
public:
    void dfs(int i, int j,vector<vector<char>>& grid, vector<vector<bool>>& visited ){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or visited[i][j] or grid[i][j]=='0')return;
        visited[i][j] = 1;
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited); 
        dfs(i,j-1,grid,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};