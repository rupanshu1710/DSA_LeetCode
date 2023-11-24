class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i = piles.size()-2;
        int x = 0;
        int ans=0;
        while(x<piles.size()/3){
            ans += piles[i];
            i-=2;
            x++;
        }
        return ans;
    }
};