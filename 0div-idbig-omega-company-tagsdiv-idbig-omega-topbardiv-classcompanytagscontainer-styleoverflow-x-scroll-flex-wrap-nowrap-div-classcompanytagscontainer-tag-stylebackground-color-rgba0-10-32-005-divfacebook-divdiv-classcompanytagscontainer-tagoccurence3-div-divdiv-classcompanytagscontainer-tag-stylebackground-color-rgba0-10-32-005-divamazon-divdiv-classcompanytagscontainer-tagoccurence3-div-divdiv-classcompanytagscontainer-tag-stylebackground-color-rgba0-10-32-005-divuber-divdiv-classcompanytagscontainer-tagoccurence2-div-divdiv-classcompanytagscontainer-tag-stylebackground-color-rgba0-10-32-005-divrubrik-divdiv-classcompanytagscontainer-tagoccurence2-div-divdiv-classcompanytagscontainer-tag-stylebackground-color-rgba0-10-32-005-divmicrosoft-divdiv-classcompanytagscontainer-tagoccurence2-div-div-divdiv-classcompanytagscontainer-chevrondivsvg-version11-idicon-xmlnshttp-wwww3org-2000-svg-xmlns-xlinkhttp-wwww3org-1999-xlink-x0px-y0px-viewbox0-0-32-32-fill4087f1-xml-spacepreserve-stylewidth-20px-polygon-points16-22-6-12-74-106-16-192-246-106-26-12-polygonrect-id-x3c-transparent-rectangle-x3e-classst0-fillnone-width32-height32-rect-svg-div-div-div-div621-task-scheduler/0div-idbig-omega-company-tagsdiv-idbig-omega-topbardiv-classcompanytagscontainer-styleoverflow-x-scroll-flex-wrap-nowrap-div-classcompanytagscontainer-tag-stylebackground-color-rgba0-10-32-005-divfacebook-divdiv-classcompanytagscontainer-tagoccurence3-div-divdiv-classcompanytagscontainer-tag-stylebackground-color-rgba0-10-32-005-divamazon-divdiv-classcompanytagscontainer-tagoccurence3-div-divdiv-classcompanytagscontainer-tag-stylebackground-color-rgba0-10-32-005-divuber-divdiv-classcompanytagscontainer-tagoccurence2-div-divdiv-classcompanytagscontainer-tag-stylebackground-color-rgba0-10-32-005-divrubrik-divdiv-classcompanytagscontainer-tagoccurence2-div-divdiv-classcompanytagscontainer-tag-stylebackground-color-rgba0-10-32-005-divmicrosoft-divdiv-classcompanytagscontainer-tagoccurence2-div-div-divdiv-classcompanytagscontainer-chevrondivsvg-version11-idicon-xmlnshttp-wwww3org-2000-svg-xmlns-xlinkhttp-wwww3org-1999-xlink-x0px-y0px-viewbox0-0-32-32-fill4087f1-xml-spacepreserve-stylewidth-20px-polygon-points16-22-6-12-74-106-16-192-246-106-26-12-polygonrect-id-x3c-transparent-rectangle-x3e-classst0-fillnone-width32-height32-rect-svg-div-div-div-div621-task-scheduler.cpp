class Solution {
public:
    bool myComparison(const pair<char,int> &a,const pair<char,int> &b){
       return a.second<b.second;
}
    int leastInterval(vector<char>& tasks, int n) {
        vector<pair<char,int>>temp;
        map<char,int>mp;
        for(auto i:tasks){
            mp[i]++;
        }
        for(auto i:mp){
            temp.push_back({i.first,i.second});
        }
        sort(temp.begin(), temp.end(),
     [](const pair<char,int>& lhs, const pair<char, int>& rhs) {
             return lhs.second < rhs.second; } );
        reverse(temp.begin(),temp.end());
        int ans=0;
        int l = tasks.size();
        int i=0;
        int m = temp.size();
        while(l>0){
            int x=0;
            for(int i=0; i<temp.size(); i++){
                l--;
                x++;
                temp[i].second--;
                if(temp[i].second==0){
                    temp.erase(temp.begin()+i);
                    i--;
                }
                if(x==n+1)break;
                
            }
            sort(temp.begin(), temp.end(),
     [](const pair<char,int>& lhs, const pair<char, int>& rhs) {
             return lhs.second < rhs.second; } );
        reverse(temp.begin(),temp.end());
            // cout<<x<<" ";
            ans += x;
            if(x<=n && l>0)ans += n-x+1;
        }
        return ans;
    }
};