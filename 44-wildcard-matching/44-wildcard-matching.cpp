class Solution {
public:
    bool f(string &s, int i , string &t, int j, vector<vector<int>> &dp){
        if(j == 0 && i == 0) return true;
        if(j == 0) return dp[i][j] = false;
        if(i == 0){
            int k = j;
            while(k > 0 && t[k-1] == '*') k--;             
            return dp[i][j] = (k == 0);
        }

        if(dp[i][j] != -1) return dp[i][j];

        
        if(t[j-1] == s[i-1] || t[j-1] == '?')
                return dp[i][j] = f(s, i-1, t , j-1, dp);

        if(t[j-1] == '*')
            return dp[i][j] = f(s, i, t, j-1, dp) || f(s, i-1, t, j, dp);


        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(s, n, p, m, dp);
    }
};