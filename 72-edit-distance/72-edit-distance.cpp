class Solution {
public:
    int f(string s, int i , string t, int j,  vector<vector<int>> &dp){
        if(j == 0) return i;
        if(i == 0) return j;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == t[j-1]) return dp[i][j] = f(s, i-1, t , j-1,dp);
        int insert = 1 + f(s, i , t, j -1, dp);
        int del = 1 + f(s, i-1, t, j, dp);
        int rep = 1 + f(s, i-1, t, j-1, dp);
        return dp[i][j] = min(insert, min(del, rep));
    }
    int minDistance(string s, string t) {
        int n  = s.size(), m  = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(s,n , t, m,dp);
    }
};