class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>a(n,0);
        int cnt=1,ans=1;
        a[k-1] = -1;
        int idx = k-1;
        while(cnt<n-1){
            int x=0;
            int i=0;
            while(x<k){
                i++;
                if(a[(idx+i)%(n)]==0)x++;
            }
            idx+=i;
            cout<<idx<<" ";
            idx%=(n);
            cnt++;
            a[idx] = -1;
            cout<<idx<<" ";
        }
        cout<<cnt<<endl;
        for(int i=0; i<n; i++){
            if(a[i]==0){
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};