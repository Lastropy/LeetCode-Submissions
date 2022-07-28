class Solution {
public:
    int f(string &s, int i1, string &t, int i2,vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(s[i1] == t[i2]) return dp[i1][i2] = 1+ f(s, i1 -1, t , i2-1, dp);
        return dp[i1][i2] = max(f(s, i1-1,t, i2 , dp), f(s, i1, t , i2-1, dp));
    }
    int longestCommonSubsequence(string s, string t) {
        // vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        // return f(s, s.size() -1, t, t.size() -1,dp);
        
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for(int i = 1; i <= s.size(); i++){
            for(int j =1; j<= t.size(); j++){
                if(s[i-1] == t[j - 1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[s.size()][t.size()];

    }
};