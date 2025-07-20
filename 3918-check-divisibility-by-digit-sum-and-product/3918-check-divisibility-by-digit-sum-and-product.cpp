class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int sz = s.size();
        int sum = 0;
        long long prod = 1;
        for(int i=0; i<sz; i++){
            sum += s[i]-'0';
            prod *= s[i]-'0';
        }
        cout<<sum <<" "<<prod<<" "<<(sum+prod)%n<<endl;
        return  !(n%(sum+prod)) ;
    }
};