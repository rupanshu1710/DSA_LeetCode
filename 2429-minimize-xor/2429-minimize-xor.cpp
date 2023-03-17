class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int>bit(32,0);
        int num = num1;
        int pos=0;
        while(num){
            if(num&1)bit[pos]++;
            pos++;
            num = num>>1;
        }
        num = num2;
        int setBitcount=0;
        while(num){
            if(num&1)setBitcount++;
            num = num>>1;
        }
        int ans=0;
        for(int i=31; i>=0 && setBitcount>0; i--){
            if(bit[i]){
                ans += pow(2,i);
                setBitcount--;
            }
        }
        if(setBitcount>0){
            for(int i=0; i<32 && setBitcount>0; i++){
                if(bit[i]==0){
                    ans += pow(2,i);
                    setBitcount--;
                }
            }
        }
        return ans;
    }
};