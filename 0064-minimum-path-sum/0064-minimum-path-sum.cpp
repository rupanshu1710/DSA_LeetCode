class Solution {
public:
    int t[201][201];
    int getAns(vector<vector<int>>& grid,int i, int j){
        if(j>grid[0].size()-1 || i>grid.size()-1){
            if(j>grid[0].size()-1 && i>grid.size()-1)return 0;
            else if(j>grid[0].size()-1){
                int total=0;
                for(int k=i+1; k<grid.size(); k++)total += grid[k][grid[0].size()-1];
                return total;
            }
            else{
                int total=0;
                for(int k=j+1; k<grid[0].size(); k++)total += grid[grid.size()-1][k];
                return total;
            }
        }
        if(t[i][j]!=-1)return t[i][j];
        return t[i][j] = grid[i][j] + min(getAns(grid,i+1,j),getAns(grid,i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid){
        memset(t,-1,sizeof(t));
        return getAns(grid,0,0);
    }
};