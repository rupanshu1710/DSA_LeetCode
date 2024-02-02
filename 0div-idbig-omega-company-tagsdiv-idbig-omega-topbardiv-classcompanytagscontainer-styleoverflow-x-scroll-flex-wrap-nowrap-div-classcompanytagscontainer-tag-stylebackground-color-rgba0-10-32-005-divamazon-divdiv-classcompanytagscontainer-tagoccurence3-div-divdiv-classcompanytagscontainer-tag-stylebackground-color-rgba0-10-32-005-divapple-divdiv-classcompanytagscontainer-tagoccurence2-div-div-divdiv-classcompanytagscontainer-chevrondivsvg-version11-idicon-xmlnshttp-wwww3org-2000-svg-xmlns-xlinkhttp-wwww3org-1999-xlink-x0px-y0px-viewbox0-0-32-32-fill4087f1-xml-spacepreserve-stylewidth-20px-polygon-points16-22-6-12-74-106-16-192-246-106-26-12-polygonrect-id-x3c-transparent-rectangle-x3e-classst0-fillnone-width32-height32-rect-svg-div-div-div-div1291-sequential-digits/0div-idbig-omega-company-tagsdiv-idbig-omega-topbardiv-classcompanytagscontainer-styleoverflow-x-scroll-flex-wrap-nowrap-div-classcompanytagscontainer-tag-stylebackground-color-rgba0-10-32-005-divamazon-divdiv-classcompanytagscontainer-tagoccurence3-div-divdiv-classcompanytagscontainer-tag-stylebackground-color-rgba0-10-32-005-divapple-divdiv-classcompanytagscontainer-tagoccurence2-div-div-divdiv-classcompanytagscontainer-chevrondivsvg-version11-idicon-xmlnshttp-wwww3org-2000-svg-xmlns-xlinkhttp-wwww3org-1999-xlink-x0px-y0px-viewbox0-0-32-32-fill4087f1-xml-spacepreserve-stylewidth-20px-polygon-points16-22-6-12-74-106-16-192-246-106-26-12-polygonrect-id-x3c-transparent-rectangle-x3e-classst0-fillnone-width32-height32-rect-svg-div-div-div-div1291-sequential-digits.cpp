class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int n = to_string(low).size();
        vector<int> ans;
        int i=0;
        long long x = stoll(s.substr(i,n));
            cout<<x<<endl;
        while(x<low){
            i++;
            cout<<x<<endl;
            if(x==123456789)return ans;
            x = stoll(s.substr(i,n));
            if(i+n==9){
                n++;
                i=-1;
            }
        }
        // cout<<x<<endl;
        while(x<=high){
            ans.push_back(x);
            if(x==123456789)return ans;
            if(i+n==9){
                n++;
                i=-1;
            }
            i++;
            // cout<<x<<endl;
            x = stoll(s.substr(i,n));
        }
        
        // // cout<<x<<endl;
        // string t = "1000000000";
        // cout<<stoll(t);
        return ans;
    }
};