class Solution {
public:
    int LCS(string s, string t){
        int n= s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i= 1; i <= n; i++){
            for(int j =1; j <= n; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    string rev(string s){
        reverse(s.begin(), s.end());
        return s;
    }
    int longestPalindromeSubseq(string s) {
        return LCS(s, rev(s));
    }
};