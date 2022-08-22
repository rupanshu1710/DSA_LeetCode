class Solution {
public:
    bool isPowerOfFour(int n) {
        if(!n)return 0;
        float a = log(n)/log(4);
        return ceil(a)==floor(a);
    }
};