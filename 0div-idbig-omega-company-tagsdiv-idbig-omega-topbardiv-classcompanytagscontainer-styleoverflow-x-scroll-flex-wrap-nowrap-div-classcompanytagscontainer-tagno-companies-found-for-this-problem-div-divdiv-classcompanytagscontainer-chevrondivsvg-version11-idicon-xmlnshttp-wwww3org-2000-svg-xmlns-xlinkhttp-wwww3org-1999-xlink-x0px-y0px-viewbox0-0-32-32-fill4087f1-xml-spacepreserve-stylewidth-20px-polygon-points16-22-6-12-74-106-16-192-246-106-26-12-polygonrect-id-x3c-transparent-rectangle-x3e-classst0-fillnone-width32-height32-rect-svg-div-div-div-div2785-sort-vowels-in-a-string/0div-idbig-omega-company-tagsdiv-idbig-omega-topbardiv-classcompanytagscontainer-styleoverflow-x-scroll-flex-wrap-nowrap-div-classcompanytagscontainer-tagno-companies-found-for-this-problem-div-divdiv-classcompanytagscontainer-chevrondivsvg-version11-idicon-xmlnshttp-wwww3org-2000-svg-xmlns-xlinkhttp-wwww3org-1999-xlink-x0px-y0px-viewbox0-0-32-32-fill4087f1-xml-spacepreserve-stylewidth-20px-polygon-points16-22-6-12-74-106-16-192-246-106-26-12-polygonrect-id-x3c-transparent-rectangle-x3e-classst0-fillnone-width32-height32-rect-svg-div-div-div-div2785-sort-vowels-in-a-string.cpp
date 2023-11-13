class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        string t = "";
        string temp1 = "";
        string temp2 = "";
        for(int i=0; i<n; i++){
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='U'||s[i]=='O'||s[i]=='a'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='e'){
                t += '0';
                if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='U'||s[i]=='O')temp1 += s[i];
                else temp2 += s[i];
            }
            else t += s[i];
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        int j=0,i=0;
        for(i=0; i<t.size() && j<temp1.size(); i++){
            if(t[i]=='0'){
                t[i] = temp1[j];
                j++;
            }
        }
        j=0;
        while(j<temp2.size() && i<n){
            if(t[i]=='0'){
                t[i] = temp2[j];
                j++;
            }
            i++;
        }
        return t;
    }
};