class Solution {
public:
    int minDeletions(string s) {
        vector<int> frq(26,0);
        int size = 0;
        for(int i=0; i<s.size(); i++){
            frq[s[i]-'a']++;
        }
        sort(frq.begin(),frq.end(),greater<int>());
        for(int i=0; i<frq.size();i++){
            if(frq[i]==0)break;
            size++;
        }
        int i=0,j=0,ans=0;
        while(i<size){
            while(frq[j]==frq[i])
            {
                j++;
                if(j==size)
                {
                    if(frq[i]==1)ans += j-i-1;
                    else
                    {
                        int b = j-i-1 - frq[i];
                        ans += ((j-i-1)*(j-i) )/2;
                        if(b>0){
                            ans -= ((b)*(b+1))/2;
                        }
                    }
                    return ans;
                }
            }
            ans += j-i-1;
            int k = j-i-1;
            int a = i+1;
            while(k){
                frq[a]--;
                a++;
                k--;
            }
            i++;
        }
        //ans += j-i+1;
        return ans;
    }
};