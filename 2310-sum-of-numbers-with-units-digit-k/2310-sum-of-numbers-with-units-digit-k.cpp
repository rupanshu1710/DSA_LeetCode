class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0)return 0;
        if(num<k)return -1;
        int unitDigit = num%10;
        int temp = -1,ans=-1;
        for(int i=1; i<=10; i++){
            
            temp = k*i;
            if(unitDigit==temp%10 && temp<=num){
                ans = i;
                break;
            }
        }
        if(unitDigit!=temp%10)return -1;
        return ans;
    }
};