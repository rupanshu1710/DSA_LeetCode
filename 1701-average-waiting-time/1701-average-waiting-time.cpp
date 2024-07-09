class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& a) {
        double ans=a[0][1];
        int time=a[0][0]+a[0][1];
        int n = a.size();
        for(int i=1; i<n; i++){
            cout<<time<<" ";
            if(time>a[i][0]){
                ans += time - a[i][0];
            }
            ans += a[i][1];
            time = max(time,a[i][0]);
            
            cout<<time<<" ";
            time += a[i][1];
        }
        return ans/n;
    }
};