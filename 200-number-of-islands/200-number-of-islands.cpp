class Solution {
public:
    void bfs(int i, int j,vector<vector<char>>& grid, vector<vector<bool>>& visited ){
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for(int a=0; a<4; a++){
                int na = i+dx[a];
                int nb = j +dy[a];
                if(na>=0 and na<m  and  nb>=0 and nb<n and grid[na][nb]=='1' and !visited[na][nb]){
                    visited[na][nb]=1;
                    q.push({na,nb});
                }
            }
        }
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
                    bfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};