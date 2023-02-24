class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";
        if(a>b){
            char x = 'a';
            char y = 'b';
            while(b--){
                ans += "aab";
                a -= 2;
            }
            if(a>=0){
                while(a>0){
                    ans += 'a';
                    a--;
                }
            } 
            else{
                while(a<0){
                    auto it = ans.find("aa");
                    ans.erase(ans.begin()+it);
                    a++;
                }
            }
        }
        else{
            char x = 'a';
            char y = 'b';
            // string ans = "";
            while(a--){
                ans += "bba";
                b-= 2;
            }
            if(b>=0){
                while(b>0){
                    ans += 'b';
                    b--;
                }
            }  
            else{
                while(b<0){
                    auto it = ans.find("bb");
                    ans.erase(ans.begin()+it);
                    b++;
                }
            }
        }
        return ans;
    }
};