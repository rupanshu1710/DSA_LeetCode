class Solution {
public:
    int reverse(int x) {
        long long int ans = 0;
        int a;
        while(x!=0)
        {
            a = x%10;
            x = x/10;
            ans = ans*10 + a;
        }
        if(ans>INT32_MAX|| ans<INT32_MIN)
        {
            return 0;
        }
        return ans;
        
    }
};