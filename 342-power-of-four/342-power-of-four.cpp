class Solution {
public:
    bool isPowerOfFour(int n) {
        if(!n)return 0;
        while(n){
            if(n!=1 && n%4!=0)return 0;
            n = n/4;
        }
        return 1;
    }
};