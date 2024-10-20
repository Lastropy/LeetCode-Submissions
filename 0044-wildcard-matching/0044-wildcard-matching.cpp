class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string &s, int idx1, string &p, int idx2) {
        if(idx1 < 0 && idx2 < 0) return true;
        if(idx2 < 0) return false;
        if(idx1 < 0) {
            while(idx2 >= 0 && p[idx2] == '*') idx2--;
            return (idx2 < 0);
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s[idx1] == p[idx2] || p[idx2] == '?'){
            return dp[idx1][idx2] = solve(s, idx1 - 1, p, idx2 - 1);
        }
        if(p[idx2] == '*'){
            // This tries all possibilites with '*'
            bool matchNone = solve(s, idx1, p, idx2 - 1);
            bool matchSome = solve(s, idx1 - 1, p, idx2);
            return dp[idx1][idx2] = matchNone || matchSome;
        }
        return dp[idx1][idx2] = false;
    }
    
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        dp.resize(m, vector<int>(n, -1));
        return solve(s, m - 1, p, n - 1);
    }
};