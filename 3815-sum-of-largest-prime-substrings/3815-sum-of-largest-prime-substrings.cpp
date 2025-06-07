class Solution {
public:
    bool isPrime(long long n){
        long long cnt=0;
        if(n <= 1 || ((n > 2) && (n%2 == 0)))return 0;
        if(n == 2)return 1;
       for(long long i=3; i*i<=n; i+=2){
            if(n%i==0)return 0;
        }
        return 1;
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        set<long long>st;
        vector<long long>temp;
        for(int i=0; i<n; i++){
            string str = "";
            for(int j=i; j<n; j++){
                str += s[j];
                long long num = stoll(str);
                // cout<<num<<" * ";
                if(isPrime(num)){
                    st.insert(num);
                    // cout<<" - ";
                    cout<<num<<" ";
                }
            }
        }
        for(auto i:st){
            temp.push_back(i);
        }
        sort(temp.begin(),temp.end(),greater<long long>());
        if(temp.size()<3){
            long long sum = 0;
            for(auto i:temp){
                sum += i;
            }
            return sum;
        }
        // cout<<isPrime(635750161)<<endl;
        return temp[0] + temp[1] + temp[2];
    }
};