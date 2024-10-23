class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string &s, string &t){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == t[j-1]){
            return dp[i][j] = 0 + solve(i-1, j-1, s, t);
        } else {
            int ins = 1 + solve(i, j - 1, s, t);
            int del = 1 + solve(i - 1, j, s, t);
            int repl = 1 + solve(i-1, j- 1, s, t);
            return dp[i][j] = min({ins,del, repl});
        }
    }
    
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return solve(m, n, s, t);
    }
};