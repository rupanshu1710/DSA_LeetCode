class Solution {
public:
    int compress(vector<char>& chars) {
        int temp=1;
        int n = chars.size();
        vector<char> ans;
        for(int i=1; i<chars.size(); i++){
            if(chars[i]==chars[i-1]){
                temp++;
            }
            else{
                ans.push_back(chars[i-1]);
                if(temp!=1){
                    string s = to_string(temp);
                    for(auto it:s){
                        ans.push_back(it);
                    }
                }
                temp=1;
            }
        }
        ans.push_back(chars[chars.size()-1]);
        if(temp!=1){
            string s = to_string(temp);
            for(auto it:s){
                ans.push_back(it);
            }
        }
        chars = ans;
        return chars.size();
    }
};