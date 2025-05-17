class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int>temp(26,0);
        int n = s.size();
        for(int i=0; i<n; i++){
            temp[s[i]-'a']++;
        }

        sort(temp.begin(),temp.end());
        int ans=0;
        int idx;
        for(int i=0; i<26; i++){
            if(temp[i]!=0){
                idx = i;
                break;
            }
        }
        cout<<idx<<endl;
        int cnt = 26-idx;
        while(cnt>k && idx<26){
            ans += temp[idx];
            cnt--;
            idx++;
        }
        return ans;
    }
};