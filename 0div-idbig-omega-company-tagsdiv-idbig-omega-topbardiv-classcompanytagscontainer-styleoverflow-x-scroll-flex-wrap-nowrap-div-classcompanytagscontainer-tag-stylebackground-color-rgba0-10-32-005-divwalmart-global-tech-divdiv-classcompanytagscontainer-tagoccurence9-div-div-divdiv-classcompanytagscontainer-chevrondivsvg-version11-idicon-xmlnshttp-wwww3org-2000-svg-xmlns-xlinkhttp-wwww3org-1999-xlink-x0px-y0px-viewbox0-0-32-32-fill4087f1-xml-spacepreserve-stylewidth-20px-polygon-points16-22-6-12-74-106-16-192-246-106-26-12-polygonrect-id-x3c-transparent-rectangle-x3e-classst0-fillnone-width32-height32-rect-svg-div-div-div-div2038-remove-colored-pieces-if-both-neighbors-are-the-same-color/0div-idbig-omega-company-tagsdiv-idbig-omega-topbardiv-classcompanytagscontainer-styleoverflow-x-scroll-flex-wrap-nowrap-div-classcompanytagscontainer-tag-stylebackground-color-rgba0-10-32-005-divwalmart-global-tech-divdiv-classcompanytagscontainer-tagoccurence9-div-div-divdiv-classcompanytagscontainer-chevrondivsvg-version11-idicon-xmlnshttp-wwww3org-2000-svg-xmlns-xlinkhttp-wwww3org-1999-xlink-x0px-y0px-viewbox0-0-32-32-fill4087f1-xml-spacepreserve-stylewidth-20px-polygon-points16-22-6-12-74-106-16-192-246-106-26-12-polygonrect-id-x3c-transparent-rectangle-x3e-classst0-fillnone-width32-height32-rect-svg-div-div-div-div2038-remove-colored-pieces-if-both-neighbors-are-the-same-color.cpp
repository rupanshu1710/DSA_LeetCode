class Solution {
public:
//     bool check(string s, bool a){
//         if(a){
//             if(s.find("AAA")!=string::npos){
//                 auto it = s.find("AAA");
//                 s.erase(s.begin()+it);
//                 return check(s,0);
//             }
//             else return 0;
//         }
//         else{
//             if(s.find("BBB")!=string::npos){
//                 auto it = s.find("BBB");
//                 s.erase(s.begin()+it);
//                 return check(s,1);
//             }
//             else return 1;
            
//         }
//     }
    bool winnerOfGame(string colors) {
        // return check(colors,1);
        int acnt=0,bcnt=0;
        for(int i=1; i<colors.size()-1; i++){
            if(colors[i-1]=='A' && colors[i+1]=='A' && colors[i]=='A')acnt++;
            if(colors[i-1]=='B' && colors[i+1]=='B'&& colors[i]=='B')bcnt++;
        }
        // cout<<acnt<<" "<<bcnt<<endl;
        if(acnt>bcnt)return 1;
        else return 0;
    }
};