class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        int cnt=0;
        for(auto i:s){
            if(i=='1')cnt++;
        }
        cnt--;
        while(cnt--){
            ans += '1';
        }
        while(ans.size()!=s.size()){
            ans += '0';
        }
        ans[ans.size()-1] = '1';
        return ans;
    }
};