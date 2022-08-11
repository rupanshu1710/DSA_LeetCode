class Solution {
public:
    int t[30001][2];
    int solve(vector<int>& prices, int idx, bool isSell){
        if(idx>prices.size()-1)return t[idx][isSell] = 0;
        if(t[idx][isSell]!=-1)return t[idx][isSell];
        if(isSell)return t[idx][isSell] =  max(prices[idx] + solve(prices,idx+1,0),solve(prices,idx+1,1));
        else return t[idx][isSell] =  max(solve(prices,idx+1,1)-prices[idx],solve(prices,idx+1,0));
    }
    int maxProfit(vector<int>& prices){
        memset(t,-1,sizeof(t));
        return solve(prices,0,0);
    }
};