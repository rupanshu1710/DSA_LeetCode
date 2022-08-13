class Solution {
public:
    /*int getAns(string s, int idx, int n){
        if(idx==n) return 1;
        if(s[idx]=='0') return 0;
        if(t[idx]!=-1)return t[idx];
        string s1 = s.substr(idx, 2);
        int ans1 = getAns(s,idx+1,n);
        t[idx+1] = ans1;
        int ans2 = 0;
        if(stoi(s1)>9 and stoi(s1)<=26){
            ans2 = getAns(s, idx+2, n);
            t[idx+2] = ans2;
        }
        return t[idx] = ans1+ans2;        
        
    }*/
    int numDecodings(string s) {
        int n=s.size();
        if(s[0] == '0') return 0;
        int t[n+1];
        for(int i=0; i<n+1; i++)t[i]=0;
        t[n] = 1;
        for(int i=s.size()-1; i>=0; i--){
            string s1 = s.substr(i, 2);
            if(s[i]!='0')t[i] += t[i+1];
            if(stoi(s1)>9 and stoi(s1)<=26){
                t[i] += t[i+2];
            }
        }
        return t[0];
    }
};