class Solution {
public:
    int t[1002];
    int solve(vector<int>& cost,int start){
        if(start>cost.size()-1)return t[start] = 0;
        if(t[start]!=-1)return t[start];
        t[start+1] = solve(cost,start+1);
        t[start+2] = solve(cost,start+2);
        return t[start] = cost[start] + min(t[start+1],t[start+2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=0; i<1002; i++)t[i]=-1;
        return min(solve(cost,0),solve(cost,1));
    }
};