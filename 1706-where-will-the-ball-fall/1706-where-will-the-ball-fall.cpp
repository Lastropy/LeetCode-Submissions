class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = i;
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ans[j] == -1) continue;
                int new_col = ans[j] + grid[i][ans[j]];
                if(ans[j] < n-1 && grid[i][ans[j]] == 1 && grid[i][ans[j] + 1] == -1) ans[j] = -1;
                else if(ans[j] - 1> 0 && grid[i][ans[j]] == -1 && grid[i][ans[j]-1] == 1) ans[j] = -1;
                else if(new_col < 0 || new_col >= n) ans[j] = -1;
                else ans[j] = new_col;
            }
        }
        
        return ans;
    }
};