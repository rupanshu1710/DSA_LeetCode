class Solution {
private:
    long long dfs(int node, vector<int> adj[], vector<bool> &visited){
        visited[node] = 1;
        int len = 1;
        for(auto i : adj[node]){
            if(!visited[i]){
                len += dfs(i, adj, visited);
            }
        }
        return len;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>a;
        vector<bool>visited(n,0);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                long long len = dfs(i, adj, visited);
                a.push_back(len);
            }
        }
        int m = a.size();
        vector<int> b(m , 0);
        b[m-1] = 0;
        for(int i = m-2; i >= 0; i--){
            b[i] = b[i+1] + a[i+1];
        }
        long long ans = 0;
        for(int i = 0; i < m; i++){
            ans += (a[i]*1LL*b[i]);
        }
        return ans;
    }
};