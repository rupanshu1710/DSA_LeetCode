class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if(n1!=n2)return 0;
        int n = n1;
        vector<int>temp1(26,0);
        vector<int>temp2(26,0);
        for(int i=0; i<n; i++){
            temp1[word1[i]-'a']++;
            temp2[word2[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(temp1[i]==0 && temp2[i]==0 || temp1[i]!=0 && temp2[i]!=0)continue;
            else return 0;
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        for(int i=0; i<26; i++){
            if(temp2[i]!=temp1[i])return 0;
        }
        return 1;
    }
};