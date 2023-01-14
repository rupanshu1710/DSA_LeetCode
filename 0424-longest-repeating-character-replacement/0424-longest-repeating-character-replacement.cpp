class Solution {
public:
    bool isCheck(string s, int len, int k){
        if(len<=k)return 1;
        int i=0,j=0,ans=0;
        vector<int>mp(26,0);
        int count=0;
        int cnt=0,mx;
        while(j<s.size()){
            int sum=0;
            mp[s[j]-'A']++;
            if(s[i]!=s[j])count++;
            mx = *max_element(mp.begin(),mp.end());
            for(int i=0; i<26; i++)sum += mp[i];
            sum -= mx;
            // if(i<s.size()-1 && s[i+1]!=s[j])cnt++;
            if(sum<=k){
                ans = max(ans,j-i+1);
                // cout<<i<<" "<<j<<" "<<count<<endl;
                if(ans>=len)return 1;
                j++;
            }
            else{
                char c = s[i];
                int x=0;
                count = j-i+1;
                while(s[i]==c){
                    mp[s[i]-'A']--;
                    i++;
                    x++;
                }
                count-=mp[s[i]-'A'];
                count -= x;
                // cnt=0;
                j++;
            }
            
        }
        if(ans>=len)return 1;
        return 0;
    }
    int characterReplacement(string s, int k) {
        int i=0,j=0,ans=0;
        vector<int>mp(26,0);
        int count=0;
        int cnt=0,mx;
        while(j<s.size()){
            int sum=0;
            mp[s[j]-'A']++;
            if(s[i]!=s[j])count++;
            mx = *max_element(mp.begin(),mp.end());
            for(int i=0; i<26; i++)sum += mp[i];
            sum -= mx;
            if(sum<=k){
                ans = max(ans,j-i+1);
                cout<<i<<" "<<j<<" "<<count<<endl;
                j++;
            }
            else{
                char c = s[i];
                while(sum>k){
                    mp[s[i]-'A']--;
                    sum--;
                    i++;
                }
                j++;
            }
            
        }
        return ans;
    }
};