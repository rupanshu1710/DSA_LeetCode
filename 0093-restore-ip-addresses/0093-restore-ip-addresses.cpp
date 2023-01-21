class Solution {
public:
    vector<string> ans;
    void getAns(string res,string curr,int index,string s){
        if(index==s.length()){
            if(curr.empty() and count(res.begin(),res.end(),'.')==3){
                ans.push_back(res);
            }
            return;
        }
        if(!curr.empty() and stoi(curr)==0){
            return;
        }
        curr.push_back(s[index]);
        if(stoi(curr)>255){
            return;
        }
        getAns(res,curr,index+1,s);
        if(!res.empty()){
            getAns(res+"."+curr,"",index+1,s);
        }
        else{
            getAns(curr,"",index+1,s);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string temp = "";
        string res = "";
        getAns(res,temp,0,s);
        return ans;
    }
};