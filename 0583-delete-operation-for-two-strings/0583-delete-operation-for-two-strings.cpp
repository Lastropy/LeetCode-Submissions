class Solution {
public:
    int minDistance(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for(int i = 0; i <= m; i++) dp[i][0] = 0;        
        for(int i = 0; i <= n; i++) dp[0][i] = 0;
        
        for(int i = 1; i <= m; i++){
            for(int j =1; j <= n; j++){
                if(s[i-1] == t[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return n + m - 2* dp[m][n];
    }
};