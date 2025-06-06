class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans="";
        int n = numFriends;
        if(n==1)return word;
        char mx = 'a';
        for(int i=0; i<word.size(); i++){
                // cout<<word[i]<<" "<<mx<<" ";
            if((char)mx<(char)word[i]){
                // cout<<word[i]<<" "<<mx<<" ";
                mx = word[i];
            }
        }
        vector<int>temp;
        for(int i=0; i<word.size(); i++){
            if(word[i]==mx)temp.push_back(i);
        }
        int i=0,j=1;
        int m = temp.size();
        int idx = temp[0];
        while(i<j && j<m){
            int sz = min((int)word.size()-n+1,max(temp[j]-temp[i]+1,(int)word.size()-temp[j]));
            string s1 = word.substr(temp[i],sz);
            string s2 = word.substr(temp[j],sz);
            // cout<<s1<<" "<<s2<<endl;
            if(s1<s2){
                idx = temp[j];
            i=j;
            j++;
            }
            else j++;
        }
        cout<<idx<<endl;
        return word.substr(idx,word.size()-n+1);
    }

};