class Solution {
public:
    void dfs(int intColour,int sr,int sc,vector<vector<int>>& grid,int colour,vector<vector<int>>& image, int delr[], int delc[]){
        int n = image.size();
        int m = image[0].size();
        grid[sr][sc] = colour;
        for(int i=0; i<4; i++){
            int nsr = sr + delr[i];
            int nsc = sc + delc[i];
            if(nsr>=0 && nsr<n && nsc>=0 && nsc<m && grid[nsr][nsc]!=colour && image[nsr][nsc]==intColour){
                dfs(intColour,nsr,nsc,grid,colour,image,delr,delc);
            }
            
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> grid = image;
        int intColour = image[sr][sc];
        int delr[4] = {-1,0,+1,0};
        int delc[4] = {0,-1,0,+1};
        dfs(intColour,sr,sc,grid,color,image,delr,delc);
        return grid;
    }
};