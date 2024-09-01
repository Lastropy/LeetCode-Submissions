class Solution {
public:
    int dfs(vector<vector<int>> &values, int idx, int mask_row, map<pair<int,int>, int> &dp){
        if(idx >= values.size()) return 0;
        if(dp.find({idx, mask_row})!= dp.end()) return dp[{idx, mask_row}];
        
        int ans = 0;
        int curr_val = values[idx][0], row = values[idx][1];
        int non_duplicate_idx = idx + values[idx][3];
        
        if(mask_row & (1 << row)) ans += dfs(values, idx+1, mask_row, dp);
        else {
            int take = curr_val + dfs(values, non_duplicate_idx, mask_row | (1 << row), dp);
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
            for(int j=0; j<m; j++)
                values.push_back({grid[i][j], i, j});
        sort(values.rbegin(), values.rend());
        
        int cnt = 1;
        values[values.size() - 1].push_back(1);
        for(int i = values.size() - 2; i>= 0; i--){
            if(values[i][0] == values[i+1][0]) cnt++;
            else cnt = 1;
            values[i].push_back(cnt);
        }
        map<pair<int,int>, int> dp;
        return dfs(values, 0, 0, dp);
    }
};