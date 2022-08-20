class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else vis[i][j]=0;
            }
        }
        int dx[] = {1, 0,-1,0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int column = q.front().first.second;
            int count = q.front().second;
            q.pop();
            ans[row][column] = count;
            for(int i=0; i<4; i++){
                int nrow = row + dx[i];
                int ncolumn = column + dy[i];
                if(nrow>=0 && nrow<n && ncolumn>=0 && ncolumn<m && !vis[nrow][ncolumn]){
                    vis[nrow][ncolumn] = 1;
                    q.push({{nrow,ncolumn},count+1});
                }
            }
        }
        return ans;
    }
};


