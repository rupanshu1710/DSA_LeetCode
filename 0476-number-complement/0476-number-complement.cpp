class Solution {
public:
    int findComplement(int num) {
        long long ans= (int)(log(num)/log(2));
        ans = pow(2,ans+1);
        return ans-1-num;
    }
};