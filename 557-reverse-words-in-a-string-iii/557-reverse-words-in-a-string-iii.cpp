class Solution {
public:
    string reverseWords(string s) {
        char c = ' ';
        string ans = "",temp = ""; 
        for(int i=0; i<s.size(); i++){
            if(s[i]!=c){
                temp += s[i];
            }
            else{
                reverse(temp.begin(),temp.end());
                ans += temp;
                ans += ' ';
                temp.clear();
            }
        }
        if(temp.size()!=0){
            reverse(temp.begin(),temp.end());
            ans += temp;
            temp.clear();
        }
        return ans;
    }
};