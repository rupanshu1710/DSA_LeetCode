/*typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
/*class Solution {
public:
    int fillCups(vector<int>& amount) {
		int i;
		FOR(i,500) {
			sort(ALL(amount));
			if(amount[2]<=0) return i;
			amount[1]--;
			amount[2]--;
		}
		return 0;
        
    }
};*/
class Solution {
public:
    void solve(vector<int>&a, int &ans){
        sort(a.begin(),a.end());
        if(a[2]==0)return;
        if(a[1]==0){
            ans += a[2];
            return;
        }
        if(a[2]>=1 && a[1]>=1){
            a[2] = a[2] - 1 ;
            a[1] = a[1] - 1 ;
            ans++;
            cout<<ans<<endl;
            solve(a,ans);
        }
        return;
    }
    int fillCups(vector<int>& a) {
        /*if(a[0]==0 && a[1]*a[2]==0)return a[0];
        if(a[1]==0 && a[0]*a[2]==0)return a[1];
        if(a[2]==0 && a[1]*a[0]==0)return a[2];*/
        int ans = 0;
        //sort(a.begin(),a.end());
        solve(a,ans);
        return ans;
    }
};