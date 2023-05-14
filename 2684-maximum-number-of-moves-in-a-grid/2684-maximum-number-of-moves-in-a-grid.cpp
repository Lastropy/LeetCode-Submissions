class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid, int r, int c, int &m, int &n){
        if(c >= n || r < 0 || r >= m || c < 0) return 0;
        if(dp[r][c]!= -1) return dp[r][c];
        
        int ans = 0;
        
        if(c < n - 1 && grid[r][c+1] > grid[r][c])
            ans = max(ans, 1+ dfs(grid, r, c+1, m , n));
        
        if(r && c < n - 1 && grid[r-1][c+1] > grid[r][c] )
            ans = max(ans, 1+ dfs(grid, r-1, c+1, m , n));
        
        if(r < m - 1 && c < n - 1 && grid[r+1][c+1] > grid[r][c] )
            ans = max(ans, 1+ dfs(grid, r+1, c+1, m , n));
        
        return dp[r][c] = ans;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int ans= 0, m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        
        for(int i =0; i < m; i++)
            ans = max(ans,dfs(grid,i,0, m, n));
        
        return ans;
    }
};