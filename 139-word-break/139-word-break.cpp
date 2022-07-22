class Solution {
public:
    bool f(string &s , int st, set<string> &t, vector<int> &dp){
        if(st == s.size()) return false;
        if(t.find(s.substr(st)) != t.end())
            return true;
        if(dp[st] != -1) return dp[st];
        string res = "";
        for(int i  = st ; i < s.size() - 1; i++){
            res += s[i];
            if(t.find(res) != t.end())
            {
                if(f(s, i+1, t,dp))
                    return dp[st] = true;
            }
        }
        return dp[st]  = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() , -1);
        set<string> st;
        for(string w: wordDict)
            st.insert(w);
        return f(s,0 , st , dp);
    }
};