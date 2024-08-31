class Solution {
public:
    void dfs(vector<vector<int>>& g, int r, int c, int &t, int &col){
        if(r < 0 || c < 0 || r >= g.size() || c >= g[r].size()) return;
        if(g[r][c] != t) return;
        g[r][c] = col;
        for(int d = -1; d <= 1; d+=2){
            dfs(g, r + d, c, t, col);
            dfs(g, r , c + d, t , col);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& g, int r, int c, int col) {
        if(g[r][c] == col) return g;
        int t = g[r][c];
        dfs(g, r, c, t, col);
        return g;
    }
};