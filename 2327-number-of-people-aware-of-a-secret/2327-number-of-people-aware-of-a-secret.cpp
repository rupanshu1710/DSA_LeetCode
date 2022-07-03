class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>ans(n+1);
        ans[0] = 0;
        ans[1] = 1;
        int mod = 1e9+7;
        for(int i =1;i<=delay;i++)ans[i] = 1;  
        
        for(int i = delay+1;i<=n;i++){
             for(int j = delay;j<forget ;j++){      
                 if(i-j<=0)break;
                 ans[i] =(ans[i]%mod + ans[i-j]%mod)%mod;
             }
               ans[i]+=1;
            
            if(i-forget>=1)ans[i]--;        
        
        }
        
        return ans[n];
    }
};