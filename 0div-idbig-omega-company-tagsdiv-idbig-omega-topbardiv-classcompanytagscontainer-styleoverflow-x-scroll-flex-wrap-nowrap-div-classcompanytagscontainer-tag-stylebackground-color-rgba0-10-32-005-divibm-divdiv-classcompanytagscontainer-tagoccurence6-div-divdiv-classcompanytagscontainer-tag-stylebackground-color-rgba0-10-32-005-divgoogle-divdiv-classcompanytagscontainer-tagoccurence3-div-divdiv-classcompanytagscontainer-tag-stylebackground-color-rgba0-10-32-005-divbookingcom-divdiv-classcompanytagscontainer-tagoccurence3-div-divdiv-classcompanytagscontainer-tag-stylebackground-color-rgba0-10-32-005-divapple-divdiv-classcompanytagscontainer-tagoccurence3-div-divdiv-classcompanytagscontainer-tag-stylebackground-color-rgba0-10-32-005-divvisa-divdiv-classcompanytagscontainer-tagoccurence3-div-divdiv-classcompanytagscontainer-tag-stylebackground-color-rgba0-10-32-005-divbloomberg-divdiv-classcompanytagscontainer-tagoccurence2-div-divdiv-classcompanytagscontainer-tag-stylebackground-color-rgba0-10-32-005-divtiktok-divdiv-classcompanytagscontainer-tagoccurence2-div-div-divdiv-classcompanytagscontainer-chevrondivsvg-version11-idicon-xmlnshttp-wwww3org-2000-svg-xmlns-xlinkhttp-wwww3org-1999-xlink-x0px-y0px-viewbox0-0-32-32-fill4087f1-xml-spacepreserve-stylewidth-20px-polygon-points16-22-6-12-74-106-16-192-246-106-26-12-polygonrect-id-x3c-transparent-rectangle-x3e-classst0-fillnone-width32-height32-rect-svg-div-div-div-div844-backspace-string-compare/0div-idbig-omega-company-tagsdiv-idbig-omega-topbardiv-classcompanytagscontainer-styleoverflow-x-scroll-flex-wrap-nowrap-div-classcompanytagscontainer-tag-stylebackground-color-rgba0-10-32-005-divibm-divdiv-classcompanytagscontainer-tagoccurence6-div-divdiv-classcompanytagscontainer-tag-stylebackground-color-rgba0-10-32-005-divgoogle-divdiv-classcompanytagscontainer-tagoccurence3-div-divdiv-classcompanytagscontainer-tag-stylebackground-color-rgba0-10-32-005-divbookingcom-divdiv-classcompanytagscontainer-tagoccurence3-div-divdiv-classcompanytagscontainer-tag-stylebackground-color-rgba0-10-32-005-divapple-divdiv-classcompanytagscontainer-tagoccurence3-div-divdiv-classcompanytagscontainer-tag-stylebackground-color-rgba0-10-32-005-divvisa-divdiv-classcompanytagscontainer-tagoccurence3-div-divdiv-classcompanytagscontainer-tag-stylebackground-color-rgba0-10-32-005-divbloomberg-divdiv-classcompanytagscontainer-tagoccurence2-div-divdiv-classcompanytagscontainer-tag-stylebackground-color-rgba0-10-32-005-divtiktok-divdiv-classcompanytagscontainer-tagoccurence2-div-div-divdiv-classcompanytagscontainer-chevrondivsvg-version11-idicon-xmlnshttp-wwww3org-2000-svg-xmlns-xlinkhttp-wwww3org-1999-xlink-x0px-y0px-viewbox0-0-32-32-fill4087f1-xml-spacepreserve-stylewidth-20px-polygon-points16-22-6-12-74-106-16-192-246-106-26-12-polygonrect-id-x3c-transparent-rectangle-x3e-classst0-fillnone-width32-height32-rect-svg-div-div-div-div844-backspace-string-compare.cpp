class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1 = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='#'){
                if(s1.size()!=0)s1.pop_back();
            }
            else s1 += s[i];
        }
        string t1 = "";
        for(int i=0; i<t.size(); i++){
            if(t[i]=='#'){
                if(t1.size()!=0)t1.pop_back();
            }
            else t1 += t[i];
        }
        cout<<s1<<" "<<t1<<endl;
        return t1==s1;
    }
};