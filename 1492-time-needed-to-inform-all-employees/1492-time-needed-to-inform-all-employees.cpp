class Solution {
public:
    int dfs(int node, map<int, vector<int>>& graph, vector<int>& visited,vector<int>& informTime) {
        // Mark the current node as visited
        visited[node] = 1;
        cout << node << " ";  // Process the node (e.g., print it)
        int ans = 0;
        // Recurse for all adjacent nodes
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                ans = max(ans,informTime[node]+dfs(neighbor, graph, visited,informTime));
            }
        }
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        // int n = manger.size();
        map<int,vector<int>>mp;

        for(int i=0; i<n; i++){
            if(i!=headID)mp[manager[i]].push_back(i);
        }
        // queue<int>q;
        vector<int>vis(n,0);
        return dfs(headID, mp, vis,informTime);
        //  ans;
    }
};