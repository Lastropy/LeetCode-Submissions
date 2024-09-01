class Solution {
public:
    int dfs(vector<vector<int>> &values, int idx, int mask_row, map<pair<int,int>, int> &dp){
        if(idx == values.size()) return 0;
        if(dp.find({idx, mask_row})!= dp.end()) return dp[{idx, mask_row}];
        
        int ans = 0;
        int curr_val = values[idx][0], row = values[idx][1];
        
        if(mask_row & (1 << row)) ans += dfs(values, idx+1, mask_row, dp);
        else {
            int j;
            for(j = idx; j < values.size() && curr_val == values[j][0]; j++){}
            int take = curr_val + dfs(values, j, mask_row | (1 << row), dp);
            int skip = 0 + dfs(values, idx+1, mask_row, dp);
            ans = max(take, skip);
        }
        return dp[{idx, mask_row}] = ans;
    }
    
    int maxScore(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> values;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                values.push_back({grid[i][j], i, j});
            }
        }
        sort(values.rbegin(), values.rend());
        map<pair<int,int>, int> dp;
        return dfs(values, 0, 0, dp);
    }
};