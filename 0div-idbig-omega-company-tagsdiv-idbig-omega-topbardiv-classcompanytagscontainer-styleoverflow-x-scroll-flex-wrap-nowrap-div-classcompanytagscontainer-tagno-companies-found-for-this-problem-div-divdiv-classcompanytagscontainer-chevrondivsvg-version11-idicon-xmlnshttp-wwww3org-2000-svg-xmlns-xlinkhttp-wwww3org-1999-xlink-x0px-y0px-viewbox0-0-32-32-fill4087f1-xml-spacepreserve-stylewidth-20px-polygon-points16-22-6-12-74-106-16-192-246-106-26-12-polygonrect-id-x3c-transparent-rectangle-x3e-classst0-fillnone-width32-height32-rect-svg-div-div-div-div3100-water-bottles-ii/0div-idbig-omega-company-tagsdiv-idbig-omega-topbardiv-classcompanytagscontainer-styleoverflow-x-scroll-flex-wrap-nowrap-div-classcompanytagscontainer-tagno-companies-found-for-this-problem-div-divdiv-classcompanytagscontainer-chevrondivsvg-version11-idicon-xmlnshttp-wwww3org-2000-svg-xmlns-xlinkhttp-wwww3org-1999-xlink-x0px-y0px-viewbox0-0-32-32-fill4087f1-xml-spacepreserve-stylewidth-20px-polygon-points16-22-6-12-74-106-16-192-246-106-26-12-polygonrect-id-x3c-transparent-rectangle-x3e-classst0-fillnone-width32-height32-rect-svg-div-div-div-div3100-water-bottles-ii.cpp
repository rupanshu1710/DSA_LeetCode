class Solution {
public:
    int maxBottlesDrunk(int numBottles, int n) {
        int ans=0;
        ans += numBottles;
        int x = ans;
        while(x>=n){
            x -= n-1;
            ans++;
            n++;
        }
        return ans;
    }
};