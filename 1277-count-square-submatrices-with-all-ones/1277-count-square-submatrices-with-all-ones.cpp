class Solution {
public:
    int countSquares(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++){
            if(g[0][i])
                dp[0][i] = 1;
        }
    
        for(int i = 0; i < m; i++){
            if(g[i][0])
                dp[i][0] = 1;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(g[i][j]){
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        
        int ans = 0;
        for(auto v: dp){
            for(auto i: v)
                ans += i;
        }
        return ans;
    }
};