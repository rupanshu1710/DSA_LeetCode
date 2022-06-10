class Solution {
public:
    int t[13][10001];
    int getAns(vector<int>& coins, int amount, int index){
        if(index==coins.size()-1){
            if(amount%coins[index]==0)return amount/coins[index];
            else return 1e9;
        }
        if(t[index][amount]!=-1)return t[index][amount];
        if(coins[index]<=amount){
            return t[index][amount] = min(1+ getAns(coins,amount-coins[index],index), getAns(coins,amount,index+1));
        }
        else{
            return t[index][amount] = getAns(coins,amount,index+1);
        }
        return t[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        return getAns(coins,amount,0)==1e9?-1:getAns(coins,amount,0);
    }
};