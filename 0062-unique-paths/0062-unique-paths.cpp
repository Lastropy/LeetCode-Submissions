class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int tar_row, int tar_col){
        if(i > tar_row || j > tar_col) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == tar_row && j == tar_col) return 1;
        return dp[i][j] = solve(i + 1, j, tar_row, tar_col) + solve(i, j + 1, tar_row, tar_col); 
    }
    
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1));
        return solve(0, 0, m-1, n-1);
    }
};