class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string ans = "";
        int n = s.size();
        string s1 = "";
        string s2 = "";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(s1);
                s1="";
            }
            else if(s[i]==')'){
                if(st.size()==0){
                    reverse(s1.begin(),s1.end());
                }
                else{
                    reverse(s1.begin(),s1.end());
                    string temp = st.top();
                    st.pop();
                    temp += s1;
                    s1 = temp;
                }
            }
            else{
                s1 += s[i];
            }

        }
        return s1;
    }
};