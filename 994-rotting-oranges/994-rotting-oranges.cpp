class Solution {
public:
    int bfs(vector<vector<int>>& grid, int ans, vector<vector<int>>& vis){
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2)q.push({{i,j},ans});
            }
        }
        int delr[4] = {0,-1,0,1};
        int delc[4] = {-1,0,1,0};
        while(!q.empty()){
            pair<int,int> p = q.front().first;
            ans = q.front().second;
            q.pop();
            int r = p.first;
            int c = p.second;
            grid[r][c]=2;
            for(int i=0; i<4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},ans+1});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        return bfs(grid,0,vis);
    }
};