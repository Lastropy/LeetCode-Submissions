class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& grid, int r, int c){
        int m = grid.size(), n = grid[0].size();
        if(c >= n || r < 0 || r >= m || c < 0) return 0;
        if(dp[r][c]!= -1) return dp[r][c];
        int ans = 0;
        if( c + 1 < n && grid[r][c+1] > grid[r][c])
            ans = max(ans, 1+ dfs(grid, r, c+1));
        if(r && c+ 1 < n&&  grid[r-1][c+1] > grid[r][c] )
            ans = max(ans, 1+ dfs(grid, r-1, c+1));
        if(r < grid.size()-1 && c+ 1< n && grid[r+1][c+1] > grid[r][c] )
            ans = max(ans, 1+ dfs(grid, r+1, c+1));
        return dp[r][c] = ans;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans= 0;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        for(int i =0; i < grid.size(); i++){
            ans = max(ans,dfs(grid,i,0));
            if(ans == grid[0].size() - 1) break;
        }
        return ans;
    }
};