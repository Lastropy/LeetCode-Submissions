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
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        // return f(s, n, t, m , dp);
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];                   
            }
        }
        return (int)dp[n][m];
        
    }
};