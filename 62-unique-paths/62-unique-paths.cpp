class Solution {
public:
    int ways( vector<vector<int>> &dp, int m , int n){
        if(m == 0 || n == 0)
            return dp[m][n] = 1;
        if(dp[m][n]!=-1)
            return dp[m][n];
        return dp[m][n] = ways(dp,m-1,n)+ ways(dp,m,n-1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return ways(dp,m-1,n-1);
    }
};