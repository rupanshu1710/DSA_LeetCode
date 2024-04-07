class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans="";
        int i=0,n=s.size();
        while(k>0 && i<n){
            // cout<<ans<<endl;
            char c = s[i];
            int x = s[i]-'a';
            int y = 'z' - s[i] + 1;
            // cout<<x<<" "<<y<<endl;
            if(k<min(x,y)){
                ans += s[i] - k;
                k=0;
            }
            else{
                if(min(x,y)==x){
                    ans += s[i] - x;
                    k -= x;
                }
                else{
                    ans += 'a';
                    k -= y;
                }
            }
            i++;
        }
        while(ans.size()!=n){
            ans += s[i];
            i++;
        }
        return ans;
    }
};