class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x==y)return 0;
        if(y>x){
            return y-x;
        }
        int k = x%11;
        k = min(k,11-k);
        int a = abs(y - x/11);
        int b = abs(y - x/5);
        int c = x%5;
        c = min(c,5-c);
        return min(x-y,1 + min(k + minimumOperationsToMakeEqual((x+k)/11,y),c+minimumOperationsToMakeEqual((x+c)/5,y)));
    }
};