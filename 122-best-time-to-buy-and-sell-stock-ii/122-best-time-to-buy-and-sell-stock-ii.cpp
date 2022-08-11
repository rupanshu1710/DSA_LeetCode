class Solution {
public:
    int t[30001][2];
    // int solve(vector<int>& prices, int idx, bool isSell){
    //     for(int i=prices[i]-1; i>=0; i--){
    //         for(int j=0; j<2; j++){
    //             if(j) t[i][j] = max(prices[i] + t[i-1][j-1]),t[i-1][j]);
    //             else t[i][j] = max(-prices[i] + t[i-1][j+1]),t[i-1][j]);
    //         }
    //     }
    //     return t[idx][0];
    //     if(t[idx][isSell]!=-1)return t[idx][isSell];
    //     if(isSell)return t[idx][isSell] =  max(prices[idx] + solve(prices,idx+1,0),solve(prices,idx+1,1));
    //     else return t[idx][isSell] =  max(solve(prices,idx+1,1)-prices[idx],solve(prices,idx+1,0));
    // }
    int maxProfit(vector<int>& prices){
        memset(t,0,sizeof(t));
        t[prices.size()][0]=0;
        t[prices.size()][1]=0;
        for(int i=prices.size()-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(!j) t[i][j] = max(prices[i] + t[i+1][1],t[i+1][0]);
                else t[i][j] = max(t[i+1][0]-prices[i],t[i+1][1]);
            }
        }
        return t[0][1];
        //return solve(prices,0,0);
    }
};