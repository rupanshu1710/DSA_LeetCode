class Solution {
public:
    int getAns(int n, bool flag){
        if(n==1 || n==2)return n-1;
        if(n%2==0)return 1 + getAns(n/2,flag);
        else{
            if(flag){
                return 1 + min(getAns(n+1,1),getAns(n+1,0));
            }
            // else 
        }
        return 1 + min(getAns(n-1,1),getAns(n-1,0));
    }
    int integerReplacement(int n) {
        if(n==INT_MAX)return 32;
        if(n==1 || n==2)return n-1;
        if(n%2==0)return 1 + integerReplacement(n/2);
        cout<<getAns(n,1)<<endl;
        cout<<getAns(n,0)<<endl;
        return min(getAns(n,1),getAns(n,0));
    }
};