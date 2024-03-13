class Solution {
public:
    int pivotInteger(int n) {
        double ans = sqrt(n*(n+1)/2);
        if(ceil(ans)==floor(ans))return ans;
        return -1;
    }
};