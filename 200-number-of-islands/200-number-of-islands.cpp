class Solution {
public:
    void mark_by_dfs(vector<vector<char>> &grid, int x, int y){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == '0' || grid[x][y] == '2')
            return;
        grid[x][y] = '2';
        mark_by_dfs(grid, x+1 , y);
        mark_by_dfs(grid, x-1 , y);
        mark_by_dfs(grid, x , y+1);        
        mark_by_dfs(grid, x , y-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j  = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    mark_by_dfs(grid,i, j);
                }
            }
        }
        return ans;
    }
};