class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        int n1 = a.size();
        int n2 = b.size();
        string temp = s.substr(0,n1);
        vector<int>idx;
        if(temp==a)idx.push_back(0);
        for(int i=1; i<=n-n1; i++){
            // cout<<temp<<endl;
            temp.erase(temp.begin());
            temp += s[i+n1-1];
            if(temp==a)idx.push_back(i);
        }
        temp = s.substr(0,n2);
        vector<int>idx1;
        if(temp==b)idx1.push_back(0);
        for(int i=1; i<=n-n2; i++){
            temp.erase(temp.begin());
            temp += s[i+n2-1];
            if(temp==b)idx1.push_back(i);
        }
//         cout<<idx.size()<<endl;
//         for(auto i:idx){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//         cout<<idx1.size()<<endl;
        
//         for(auto i:idx1){
//             cout<<i<<" ";
//         }
        vector<int> ans;
        int i=0; int j=0;
        if(idx1.size()!=0){
            int mx = idx1[idx1.size()-1];
            int mn = idx1[0];
            for(int i=0; i<idx.size(); i++){
                int x = idx[i] - k;
                int y = idx[i] + k;
                auto it1 = lower_bound(idx1.begin(), idx1.end(), x) -idx1.begin();
                auto it2 = upper_bound(idx1.begin(), idx1.end(), y) -idx1.begin();
                if(it2-it1>0)ans.push_back(idx[i]);
            }
        }
        return ans;
    }
};