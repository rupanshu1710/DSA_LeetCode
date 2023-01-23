class Solution {
public:
    bool isPalindrome(string s){
        string temp = s;
        reverse(s.begin(),s.end());
        return temp==s;
    }
    void getAns(string s, int idx, vector<string>& res, vector<vector<string>>& ans){
        if(idx>=s.size()){
            ans.push_back(res);
            return;
        }
        string temp = "";
        for(int i=idx; i<s.size(); i++){
            temp += s[i];
            if(isPalindrome(temp)){
                res.push_back(temp);
                getAns(s,i+1,res,ans);
                res.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>res;
        getAns(s,0,res,ans);
        return ans;
    }
};