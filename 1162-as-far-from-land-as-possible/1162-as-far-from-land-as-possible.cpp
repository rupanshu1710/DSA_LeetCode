class point{
    public:
    int x;
    int y;
    point(int X,int Y){
        x=X;y=Y;
    }
};
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<point> q;
        int n = grid.size();
        vector<vector<int>> map(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    q.push(point(i,j));
                    map[i][j]=0;
                }
            }
        }
        int maxi = -1;
        while(!q.empty()){
            point temp = q.front();
            q.pop();
            int x = temp.x;
            int y = temp.y;
            maxi = max(maxi,map[x][y]);
            if(x>0 && map[x-1][y]<0){
                map[x-1][y] = map[x][y]+1;
                q.push(point(x-1,y));
            }
            if(x<n-1 && map[x+1][y]<0){
                map[x+1][y] = map[x][y]+1;
                q.push(point(x+1,y));
            }
            if(y>0 && map[x][y-1]<0){
                map[x][y-1] = map[x][y]+1;
                q.push(point(x,y-1));
            }
            if(y<n-1 && map[x][y+1]<0){
                map[x][y+1] = map[x][y]+1;
                q.push(point(x,y+1));
            }
        }
        return maxi==0?-1:maxi;
    }
};