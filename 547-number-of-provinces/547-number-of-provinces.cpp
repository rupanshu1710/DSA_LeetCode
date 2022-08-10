class Solution {
public:
    void dfs(int i,vector<int> adjLs[], vector<int>& isVisited){
        isVisited[i]=1;
        for(auto it:adjLs[i]){
            if(!isVisited[it]){
                dfs(it,adjLs,isVisited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans=0;
        vector<int>adjLs[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && j!=i){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> isVisited(n,0);
        for(int i=0; i<n; i++){
            if(!isVisited[i]){
                ans++;
                dfs(i,adjLs,isVisited);
            }
        }
        return ans;
    }
};