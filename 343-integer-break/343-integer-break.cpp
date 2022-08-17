class Solution {
public:
    int integerBreak(int n) {
        if(n==2)return 1;
        if(n==3)return 2;
        if(n==4)return 4;
        if(n==5)return 6;
        if(n%3==0)return pow(3,n/3);
        else {
            int x = n%3;
            if(x==1)return (integerBreak(n-x)/3)*4;
            else return integerBreak(n-x)*2;
        }
    }
};