class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // double slope;
        int n = points.size();
        if(n<=2)return n;
        int ans = INT_MIN;
        int count = 0;
        for(int i=0; i<n-1; i++){
            // cout<<slope<<endl;
            int cnt=0;
            map<double,int>mp;
            for(int j=i+1; j<n; j++){
                if(points[j][0] != points[i][0]){
                    double slope = numeric_limits<double>::infinity();
                    slope=(double)((double)(points[j][1] - points[i][1])/(double)(points[j][0] - points[i][0]));
                    mp[slope]++;
                    ans = max(ans,mp[slope]);
                }
                else{
                    mp[(double)INT_MAX]++;
                    ans = max(ans,mp[(double)INT_MAX]);
                }
            }
        } 
        // for(auto i:mp){
        //     ans= max(ans,i.second);
        //     if(i.second==105)cout<<i.first<<" "<<i.second<<endl;
        // }
        // cout<<ans<<endl;
        // ans = 1 + sqrt(1+8*ans);
        // ans /=2;
        return ans+1;
    }
};