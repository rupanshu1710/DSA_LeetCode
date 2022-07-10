// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
void solve(vector<vector<int>>&grid, vector<vector<int>> &ans, vector<int> res,int i, int j){
    if(i==grid.size()-1 && j==grid[0].size()-1){
        res.push_back(grid[i][j]);
        ans.push_back(res);
        res.clear();
        return;
    }
    res.push_back(grid[i][j]);
    if(i!=grid.size()-1)solve(grid,ans,res,i+1,j);
    if(j!=grid[0].size()-1)solve(grid,ans,res,i,j+1);
    return;
}
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        vector<int> res;
        solve(grid,ans,res,0,0);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends