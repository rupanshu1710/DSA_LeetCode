class Solution {
public:
    int numRescueBoats(vector<int>& temp, int limit) {
        int n = temp.size();
        int ans=0,sum=0;
        // vector<int>temp;
        // unordered_map<int,int>mp;
        // for(auto i:people){
        //     if(i==limit){
        //         ans++;
        //     }
        //     else mp[i]++;
        // }
        // cout<<ans<<endl;
        // for(int i=0; i<n; i++){
        //     if(people[i]!=limit){
        //         if(mp.find(limit-people[i])!=mp.end() && mp.find(people[i])!=mp.end()){
        //             cout<<people[i]<<endl;
        //             ans++;
        //             mp[people[i]]--;
        //             mp[limit-people[i]]--;
        //             if(mp[people[i]]==0)mp.erase(people[i]);
        //             if(mp[limit-people[i]]==0)mp.erase(limit-people[i]);
        //         }
        //         else if(mp.find(people[i])!=mp.end())temp.push_back(people[i]);
        //     }
        // }
        // cout<<ans<<" "<<temp.size()<<endl;
        // if(temp.size()==0)return ans;
        // if(temp.size()==1)return ans+1;
        sort(temp.begin(),temp.end());
        int i=0;
        int j=temp.size()-1;
        while(i<=j){
            if(temp[i]+temp[j]>limit){
                ans++;
                j--;
            }
            else{
                ans++;
                i++;
                j--;
            }
        }
        cout<<ans<<endl;
        return ans;
        // return ans + (sum+limit-1)/limit;
    }
};