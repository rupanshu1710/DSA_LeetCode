class Solution {
public:
    vector<int> memo; // -1 not visited, 0 = false, 1 = true
    
    bool wordBreak(string s, vector<string>& wordDict) {
        memo = vector<int>(s.size()+1, -1);
        return backtrack(s, wordDict, 0);
    }
    
    bool backtrack(string& s, vector<string>& wordDict, int idx)
    {
        if (memo[idx] >= 0)
            return memo[idx];
        
        if (idx == s.size())
        {
            return true;
        }        
        
        for (const auto& word: wordDict)
        {
            if (idx + word.size()-1 <= s.size() && s.substr(idx, word.size()) == word)
            {
                memo[idx+word.size()] = backtrack(s, wordDict, idx + word.size());
                if (memo[idx+word.size()])
                    return true;
            }
        }
        
        memo[idx] = false;
        return memo[idx];
        
    }
};