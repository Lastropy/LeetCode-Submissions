class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s, int i, string &t, int j) {
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1]){
            return dp[i][j] = solve(s, i - 1, t, j - 1) + solve(s, i-1, t, j);
        }
        return dp[i][j] = solve(s, i - 1, t, j);
    }
    
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return 0;
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return solve(s, m, t, n);
    }
};