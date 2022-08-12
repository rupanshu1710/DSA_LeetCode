class Solution {
public:
    int t[50001][2];
    int maxProfit(vector<int>& prices,int fee){
        memset(t,0,sizeof(t));
        t[prices.size()][0]=0;
        t[prices.size()][1]=0;
        for(int i=prices.size()-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(!j) t[i][j] = max(prices[i] + t[i+1][1]-fee,t[i+1][0]);
                else t[i][j] = max(t[i+1][0]-prices[i],t[i+1][1]);
            }
        }
        return t[0][1];
    }
};