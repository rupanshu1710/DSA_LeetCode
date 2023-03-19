class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<int>vis(1001,0);
        queue<int>q;
        int ans=0;
        q.push(start);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                int temp = q.front();
                q.pop();
                if(temp==goal)return ans;
                if(temp>1000 || temp<0 || vis[temp]==1)continue;
                vis[temp]=1;
                for(auto i:nums){
                    q.push(temp+i);
                    q.push(temp^i);
                    q.push(temp-i);
                }
            }
            ans++;
        }
        return -1;
    }
};