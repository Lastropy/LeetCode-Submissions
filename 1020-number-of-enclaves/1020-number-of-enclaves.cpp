class Solution {
private:
      int di[4] = {-1,0,1,0};      
      int dj[4] = {0,-1,0,1};
public:
    void dfs(vector<vector<int>>& g, int i, int j){
        if(i < 0 || j < 0 || i >= g.size() || j >= g[i].size()) return;
        if(g[i][j] != -1) return;
        g[i][j] = 1;
        for(int k = 0; k < 4; k++){
            dfs(g, i+di[k], j + dj[k]);
        }
    }
    int numEnclaves(vector<vector<int>>& g) {
        int m = g.size(),n = g[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == 1){
                    g[i][j] = -1;
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            if(g[i][0] == -1) dfs(g, i, 0);            
            if(g[i][n-1] == -1) dfs(g, i, n-1);
        }
        
        for(int i = 0; i < n-1; i++){
            if(g[0][i] == -1) dfs(g, 0, i);            
            if(g[m-1][i] == -1) dfs(g, m-1, i);
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == -1) {ans++; g[i][j] = 1;}
            }
        }
        return ans;
    }
};