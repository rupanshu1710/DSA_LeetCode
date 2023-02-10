class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int  i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                // else if(grid[i][j]==1)
            }
        }
        int time=0;
        int i[4] = {1,-1,0,0};
        int j[4] = {0,0,-1,1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            time = q.front().second;
            q.pop();
            grid[x][y] = 2;
            // time++;
            for(int it=0; it<4; it++){
                int inew = x+i[it];
                int jnew = y+j[it];
                if(inew>=0 && inew<n && jnew>=0 && jnew<m && !vis[inew][jnew] && grid[inew][jnew]==1){
                    q.push({{inew,jnew},time+1});
                    vis[inew][jnew] = 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return time;
    }
};