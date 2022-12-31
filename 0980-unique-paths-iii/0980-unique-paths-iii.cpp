class Solution {
public:
    int solve(vector<vector<int>> &grid, int i , int j, int noe){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == -1)
            return 0;
        // cout<< i << " " << j << endl;
        if(grid[i][j] == 2)
            return noe == 0;
        
        grid[i][j] = -1;
        int up    = solve(grid, i + 1, j, noe - 1);
        int down  = solve(grid, i - 1, j, noe - 1);
        int left  = solve(grid, i, j + 1, noe - 1);
        int right = solve(grid, i, j - 1, noe - 1);
        
        grid[i][j] = 0;
        return up + down  + left + right;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sr = -1, sc = -1, noe = 0;
        
        for(int i = 0; i<  grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) sr = i, sc = j;
                else if(grid[i][j] == 0) noe++;
            }
        }
        
        int ans = solve(grid, sr, sc, noe+1);
        return ans;
    }
};