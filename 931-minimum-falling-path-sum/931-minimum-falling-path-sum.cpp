class Solution {
public:
    int solve(vector<vector<int>> &mat, int &n, int row, int col, vector<vector<int>> &dp){
        if(row == n) return 0;
        if(col >= n || col < 0) return 1e9;
        if(dp[row][col] != -1e9) return dp[row][col];
        
        int ans = mat[row][col] + min({solve(mat, n, row+1, col, dp),
                                       solve(mat, n, row+1, col-1, dp),
                                       solve(mat, n, row + 1, col + 1, dp)});
        
        return dp[row][col] = ans;
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = 1e9;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        for(int i = 0; i < n; i++)
            ans = min(ans, solve(matrix, n, 0, i, dp));
        return ans;
    }
};