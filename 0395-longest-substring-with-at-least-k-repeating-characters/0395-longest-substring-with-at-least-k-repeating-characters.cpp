class Solution {
public:
    int longestSubstring(string s, int t) {
        int ans = 0;
        map<char,int>mp1;
        for(auto i:s)mp1[i]++;
        vector<int>mp2;
        for(int i=0; i<s.size(); i++){
            if(mp1[s[i]]<t)mp2.push_back(i);
        }
        for(int i=0; i<mp2.size(); i++){
            cout<<mp2[i]<<" ";
        }
        cout<<endl;
        if(mp2.size()==0){
            vector<int>mp(26,0);
            int i=0,j=0,x=0;
            while(j<s.size()){
                mp[s[j]-'a']++;
                x=0;
                for(int k=0; k<26; k++){
                    if(mp[k]!=0 && mp[k]<t){
                        x++;
                        break;
                    }
                }
                if(x==0){
                    ans = max(ans,j-i+1);
                    j++;
                }
                else j++;
            }
            return ans;
        }
        int a=0;
        int b=0;
        string str = s.substr(0,mp2[a]);
        cout<<str<<endl;
        int i=0,j=0,x=0;
        vector<int>mp(26,0);
        vector<int>temp(26,0);
        for(int i=0; i<str.size(); i++){
            temp[str[i]-'a']++;
        }
        while(j<str.size()){
            if(temp[str[j]-'a']!=0 && temp[str[j]-'a']>=t){
                mp[str[j]-'a']++;
                x=0;
                for(int k=0; k<26; k++){
                    if(mp[k]!=0 && mp[k]<t){
                        x++;
                        break;
                    }
                }
                if(x==0){
                    ans = max(ans,j-i+1);
                    j++;
                }
                else j++;
            }
            else if(temp[str[j]-'a']!=0){
                while(i!=j){
                    mp[str[i]-'a']--;
                    i++;
                }
                j++;
                i++;
            }
        }
        cout<<ans<<endl;
        while(a+1<int(mp2.size())){
            string str = s.substr(mp2[a]+1,mp2[a+1]-mp2[a]-1);
            // cout<<mp2[a]<<endl;
            cout<<str<<endl;
            int i=0,j=0,x=0;
            vector<int>mp(26,0);
            vector<int>temp(26,0);
            for(int i=0; i<str.size(); i++){
                temp[str[i]-'a']++;
            }
            while(j<str.size()){
                if(temp[str[j]-'a']!=0 && temp[str[j]-'a']>=t){
                    mp[str[j]-'a']++;
                    x=0;
                    for(int k=0; k<26; k++){
                        if(mp[k]!=0 && mp[k]<t){
                            x++;
                            break;
                        }
                    }
                    if(x==0){
                        ans = max(ans,j-i+1);
                        j++;
                    }
                    else j++;
                }
                else if(temp[str[j]-'a']!=0){
                    while(i!=j){
                        mp[str[i]-'a']--;
                        i++;
                    }
                    j++;
                    i++;    
                }
                cout<<ans<<endl;
            }
            a++;
        }
        // cout<<2<<endl;
        str = s.substr(mp2[a]+1,s.size()-1-mp2[a]);
        cout<<str<<endl;
        cout<<str<<endl;
        i=0,j=0,x=0;
        vector<int>mp3(26,0);
        vector<int>temp1(26,0);
        for(int i=0; i<str.size(); i++){
            temp1[str[i]-'a']++;
        }
        while(j<str.size()){
            if(temp1[str[j]-'a']!=0 && temp1[str[j]-'a']>=t){
                mp3[str[j]-'a']++;
                x=0;
                for(int k=0; k<26; k++){
                    if(mp3[k]!=0 && mp3[k]<t){
                        x++;
                        break;
                    }
                }
                if(x==0){
                    ans = max(ans,j-i+1);
                    // cout<<ans<<endl;
                    j++;
                }
                else j++;
            }
            else if(temp1[str[j]-'a']!=0){
                while(i!=j){
                    mp3[str[i]-'a']--;
                    i++;
                }
                j++;
                i++;
            }
        }
        cout<<ans<<endl;
        // cout<<ans<<endl;
        return ans;
    }
};