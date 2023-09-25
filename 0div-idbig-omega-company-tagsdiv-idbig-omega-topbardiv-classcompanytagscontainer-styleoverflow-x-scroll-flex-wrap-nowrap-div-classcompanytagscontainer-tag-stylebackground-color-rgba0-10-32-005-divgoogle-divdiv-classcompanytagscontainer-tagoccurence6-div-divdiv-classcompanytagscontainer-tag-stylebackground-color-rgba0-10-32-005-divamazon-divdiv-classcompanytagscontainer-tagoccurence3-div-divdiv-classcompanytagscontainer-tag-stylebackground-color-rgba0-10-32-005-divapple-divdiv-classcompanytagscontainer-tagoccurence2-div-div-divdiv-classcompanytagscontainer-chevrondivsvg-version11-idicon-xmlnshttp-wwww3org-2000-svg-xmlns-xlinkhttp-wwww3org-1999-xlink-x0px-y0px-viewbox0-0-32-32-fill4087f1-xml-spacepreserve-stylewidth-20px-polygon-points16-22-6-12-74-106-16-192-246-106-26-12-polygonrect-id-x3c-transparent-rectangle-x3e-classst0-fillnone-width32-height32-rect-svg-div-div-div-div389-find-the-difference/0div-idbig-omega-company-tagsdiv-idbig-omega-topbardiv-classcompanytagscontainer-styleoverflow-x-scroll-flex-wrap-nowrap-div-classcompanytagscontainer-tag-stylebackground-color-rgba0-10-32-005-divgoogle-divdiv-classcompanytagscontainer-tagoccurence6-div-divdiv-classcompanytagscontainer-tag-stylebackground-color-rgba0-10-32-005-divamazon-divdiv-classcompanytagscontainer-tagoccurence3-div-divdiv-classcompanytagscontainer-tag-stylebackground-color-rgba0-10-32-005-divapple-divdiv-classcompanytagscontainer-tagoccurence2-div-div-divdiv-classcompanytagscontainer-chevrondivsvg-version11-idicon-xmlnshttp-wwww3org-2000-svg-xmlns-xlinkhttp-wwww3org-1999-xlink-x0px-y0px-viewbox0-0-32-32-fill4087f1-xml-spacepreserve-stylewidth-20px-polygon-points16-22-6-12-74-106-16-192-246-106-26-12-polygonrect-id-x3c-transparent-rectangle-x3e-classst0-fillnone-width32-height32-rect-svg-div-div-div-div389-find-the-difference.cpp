class Solution {
public:
    char findTheDifference(string s, string t) {
        char a = 0;
        for(auto i:s)
        {
            a = a^i;
        }
        for(auto i:t)
        {
            a = a^i;
        }
        return a;
    }
};