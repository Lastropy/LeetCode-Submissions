class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int tar_row, int tar_col, vector<vector<int>>& g){
        if(i > tar_row || j > tar_col || g[i][j] == 1) return 0;
        if(i == tar_row && j == tar_col) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i + 1, j, tar_row, tar_col, g) + solve(i, j + 1, tar_row, tar_col, g);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        dp.resize(m, vector<int> (n, -1));
        return solve(0, 0, m-1, n - 1, g);
    }
};