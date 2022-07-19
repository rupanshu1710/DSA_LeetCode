class Solution {
public:
    int t[101][10001]; 
    int solve(int k, int n) {
        if(n==0 || k==1 || n==1)return t[k][n] = n;
        if(t[k][n]!=-1)return t[k][n];
        int ans=1000000;
        int i=1; 
        int j=n;
        while(i<=j){
            int mid = i+(j-i)/2;
            if(t[k-1][mid-1]==-1 && t[k][n-mid]==-1){
                int temp1 = solve(k-1,mid-1);
                int temp2 = solve(k,n-mid);
                int temp = 1 + max(temp1,temp2);
                if(temp1<temp2){
                    i = mid+1;
                }
                else j = mid-1;
                ans = min(ans,temp);
            }
            else if(t[k-1][mid-1]==-1){
                int temp1 = solve(k-1,mid-1);
                int temp2 = t[k][n-mid];
                int temp = 1 + max(temp1,temp2);
                if(temp1<temp2){
                    i = mid+1;
                }
                else j = mid-1;
                ans = min(ans,temp);
            }
            else if(t[k][n-mid]==-1){
                int temp1 = t[k-1][mid-1];
                int temp2 = solve(k,n-mid);
                int temp = 1 + max(temp1,temp2);
                if(temp1<temp2){
                    i = mid+1;
                }
                else j = mid-1;
                ans = min(ans,temp);
            }
            else{
                int temp1 = t[k-1][mid-1];
                int temp2 = t[k][n-mid];
                int temp = 1 + max(temp1,temp2);
                if(temp1<temp2){
                    i = mid+1;
                }
                else j = mid-1;
                ans = min(ans,temp);
            }
        }
        /*for(int i=1; i<n+1; i++){
            if(t[k-1][i-1]==-1 && t[k][n-i]==-1){
                int temp = 1 + max(solve(k-1,i-1),solve(k,n-i));
                ans = min(ans,temp);
            }
            else if(t[k-1][i-1]==-1){
                int temp = 1 + max(solve(k-1,i-1),t[k][n-i]);
                ans = min(ans,temp);
            }
            else if(t[k][n-i]==-1){
                int temp = 1 + max(t[k-1][i-1],solve(k,n-i));
                ans = min(ans,temp);
            }
            else{
                int temp = 1 + max(t[k-1][i-1],t[k][n-i]);
                ans = min(ans,temp);
            }
        }*/
        return t[k][n] = ans;
    }
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return solve(k,n);
         
    }
};
    