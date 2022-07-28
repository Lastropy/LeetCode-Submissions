class Solution {
public:
    int f(string &s, int i1, string &t, int i2,vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s[i1] == t[i2]) return dp[i1][i2] = 1+ f(s, i1 -1, t , i2-1, dp);
        return dp[i1][i2] = max(f(s, i1-1,t, i2 , dp), f(s, i1, t , i2-1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return f(text1, text1.size() -1, text2, text2.size() -1,dp);
    }
};