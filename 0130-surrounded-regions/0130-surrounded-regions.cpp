class Solution {
public:
    void dfs(vector<vector<char>>& g, int i, int j){
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size()) return;
        if(g[i][j] != 'O') return;
        g[i][j] = '-';
        dfs(g, i+1, j);
        dfs(g, i-1, j);
        dfs(g, i, j+1);
        dfs(g, i, j-1);
    }
    void solve(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();        
        for(int i = 0; i < m; i++){
            if(g[i][0] == 'O') dfs(g, i, 0);
            if(g[i][n - 1] == 'O') dfs(g, i, n - 1);
        }
        
        for(int i = 0; i < n; i++){
            if(g[0][i] == 'O') dfs(g, 0, i);
            if(g[m-1][i] == 'O') dfs(g, m - 1, i);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == '-') g[i][j] = 'O';
                else if(g[i][j] == 'O') g[i][j] = 'X';
            }
        }
    }
};