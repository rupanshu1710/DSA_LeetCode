class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0,cnt1=0;
        for(auto i:bank[0]){
            if(i=='1')cnt1++;
        }
        for(int i=1; i<bank.size(); i++){
            string temp = bank[i];
            int cnt=0;
            for(int j=0; j<temp.size(); j++){
                if(temp[j]=='1')cnt++;
            }
            if(cnt==0)continue;
            else{
                // cout<<cnt<<" "<<cnt1<<endl;
                ans += cnt*cnt1;
                cnt1 = cnt;
            }
        }
        return ans;
    }
};