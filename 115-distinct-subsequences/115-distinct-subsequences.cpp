class Solution {
public:
    int f(string &s, int i , string &t, int j, vector<vector<int>> &dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = f(s, i-1, t, j, dp);
        if(s[i - 1] == t[j-1] )
            ans += f(s, i-1, t , j-1, dp);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(s, n, t, m , dp);
    }
};