class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            cout<<ans<<endl;
            int x = numBottles/numExchange;
            int y = numBottles%numExchange;
            ans +=x;
            numBottles = x+y;
        }
        return ans;
    }
};