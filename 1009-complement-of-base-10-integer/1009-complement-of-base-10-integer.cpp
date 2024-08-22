class Solution {
public:
    int bitwiseComplement(int num) {
        if(num==0)return 1;
        long long ans= (int)(log(num)/log(2));
        ans = pow(2,ans+1);
        return ans-1-num;
    }
};