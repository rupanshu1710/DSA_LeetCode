class Solution {
public:
    int maxDiff(int num) {
        int ans = 0;
        string s1 = to_string(num);
        int i = 0;
        for(i=0; i<s1.size(); i++){
            if(s1[i]!='9')break;
        }
        cout<<i<<endl;
        char c = s1[i];
        for(int j=0; j<s1.size(); j++){
            if(s1[j]==c)s1[j] = '9';
        }
        int num1 = stoi(s1);
        cout<<s1<<endl;
        i = 0;

        s1 = to_string(num);
        for(i=0; i<s1.size(); i++){
            if(s1[i]!='1' && s1[i]!='0')break;
        }
        c = s1[i];
        for(int j=0; j<s1.size(); j++){
            if(i!=0){
                if(s1[j]==c)s1[j]  = '0';
            }
            else{
                if(s1[j]==c)s1[j]  = '1';
            }
        }
        cout<<s1<<endl;
        ans = abs(min(num,stoi(s1)) - num1);
        // string s = to_string(num);
        // i = 0;
        // for(i=0 ;i<s.size(); i++){
        //     if(s[i]!='1')break;
        // }
        // cout<<i<<endl;
        // c = s[i];
        // for(int j=0; j<s.size(); j++){
        //     if(s[j]==c)s[j] = '1';
        // }
        // num1 = stoi(s);
        // cout<<s<<endl;
        // s = to_string(num);
        // for(int j=0; j<s.size(); j++){
        //     if(s[j]=='1')s[j]  = '9';
        // }
        // cout<<s<<endl;
        // ans = max(ans,abs(stoi(s) - num1));
        return ans;
    }
};