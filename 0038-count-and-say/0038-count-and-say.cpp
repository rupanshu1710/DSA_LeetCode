class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        string ans = countAndSay(n-1);
        string temp = "";
        int cnt=1;
        for(int i=1; i<ans.size(); i++){
            if(ans[i]==ans[i-1])cnt++;
            else{
                temp += cnt+'0' ;
                temp += ans[i-1];
                cnt=1;
            }
        }
        temp += cnt+'0' ;
        temp += ans[ans.size()-1];
        cnt=1;
        return temp;
    }
};