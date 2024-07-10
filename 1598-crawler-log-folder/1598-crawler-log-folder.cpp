class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        for(auto i:logs){
            if(i=="../"){
                if(st.size()!=0){
                    st.pop();
                }
            }
            else if(i=="./")continue;
            else{
                st.push(i);
            }
        }
        return st.size();
    }
};