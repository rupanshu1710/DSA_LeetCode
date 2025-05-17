class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long totalSum = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                totalSum += grid[i][j];
            }
        }

        long long rowSum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rowSum += grid[i][j];
            }
            if(rowSum*2==totalSum)return 1;
        }
        long long colSum=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                colSum += grid[j][i];
            }
            if(colSum*2==totalSum)return 1;
        }
        return 0;
    }
};