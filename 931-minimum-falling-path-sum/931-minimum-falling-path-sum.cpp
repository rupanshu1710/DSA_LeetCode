class Solution {
public:
    int t[101][101];
    int getAns(int i,int j, vector<vector<int>>& matrix){
        if(i>matrix.size()-1)return 0;
        if(t[i][j]!=-1)return t[i][j];
        if(j==0){
            return t[i][j] = matrix[i][j] + min(getAns(i+1,j,matrix),getAns(i+1,j+1,matrix));
        }
        if(j==matrix[0].size()-1){
            return t[i][j] = matrix[i][j] + min(getAns(i+1,j,matrix),getAns(i+1,j-1,matrix));
        }
        else{
            return t[i][j] = matrix[i][j] + min(min(getAns(i+1,j,matrix),getAns(i+1,j+1,matrix)),getAns(i+1,j-1,matrix));
        } 
        //return matrix[i][j] + ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix){
        memset(t,-1,sizeof(t));
        int minSum=INT_MAX;
        for(int i=0; i<matrix[0].size(); i++){
            int ans = getAns(0,i,matrix);
            minSum = min(ans,minSum);
        }
        return minSum;
    }
};