class Solution {
public:
    void mark_by_dfs(vector<vector<char>> &g, int x, int y){
        if(x < 0 || x >= g.size() || y < 0 || y >= g[0].size() || g[x][y] == '0')
            return;
        g[x][y] = '0';
        mark_by_dfs(g, x+1 , y);
        mark_by_dfs(g, x-1 , y);
        mark_by_dfs(g, x , y+1);        
        mark_by_dfs(g, x , y-1);
    }
    
    int numIslands(vector<vector<char>>& g) {
        int ans = 0;
        for(int i = 0; i < g.size(); i++){
            for(int j  = 0; j < g[0].size(); j++){
                if(g[i][j] == '1'){
                    ans++;
                    mark_by_dfs(g,i, j);
                }
            }
        }
        return ans;
    }
};