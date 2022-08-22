class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int noRow = graph.size();
        int noColmn = graph[0].size();
        vector<int> vis(noRow,-1);
        queue<int> q;
        for(int i=0; i<noRow; i++){
            if(vis[i]==-1){
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it: graph[node]){
                        if(vis[it]==-1){
                            vis[it] = 1 - vis[node];
                            q.push(it);
                        }
                        else if(vis[it] == vis[node])return 0;
                    }
                }
            }
        }
        return 1;
    }
};