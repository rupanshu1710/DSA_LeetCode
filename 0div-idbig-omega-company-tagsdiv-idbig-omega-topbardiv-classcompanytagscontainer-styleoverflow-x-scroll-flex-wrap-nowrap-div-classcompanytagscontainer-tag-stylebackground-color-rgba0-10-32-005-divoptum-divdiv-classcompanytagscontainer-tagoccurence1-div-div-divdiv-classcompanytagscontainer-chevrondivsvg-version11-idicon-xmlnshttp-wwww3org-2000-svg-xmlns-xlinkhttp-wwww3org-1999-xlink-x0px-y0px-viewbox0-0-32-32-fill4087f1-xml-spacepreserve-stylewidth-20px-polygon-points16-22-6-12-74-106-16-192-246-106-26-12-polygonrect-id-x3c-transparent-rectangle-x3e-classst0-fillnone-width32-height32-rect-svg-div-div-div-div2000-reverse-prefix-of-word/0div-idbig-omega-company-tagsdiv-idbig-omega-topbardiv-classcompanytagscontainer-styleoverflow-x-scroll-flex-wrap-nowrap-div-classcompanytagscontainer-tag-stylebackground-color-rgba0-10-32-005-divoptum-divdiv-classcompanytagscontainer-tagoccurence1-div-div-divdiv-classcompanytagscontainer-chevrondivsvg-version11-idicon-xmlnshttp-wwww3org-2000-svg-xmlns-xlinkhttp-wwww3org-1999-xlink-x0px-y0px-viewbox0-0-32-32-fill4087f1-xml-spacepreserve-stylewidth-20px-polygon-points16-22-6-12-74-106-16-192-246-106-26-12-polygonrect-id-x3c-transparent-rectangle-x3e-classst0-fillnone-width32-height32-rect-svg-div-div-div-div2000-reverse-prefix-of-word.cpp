class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j=0;
        int n = word.size();
        for(int i=0; i<n; i++){
            if(ch==word[i]){
                j=i;
                break;
            }
        }
        string s ="";
        if(j<n)s += word.substr(0,j+1);
        string t = word.substr(j+1,n-j-1);
        reverse(s.begin(),s.end());
        return s+t;
    }
};