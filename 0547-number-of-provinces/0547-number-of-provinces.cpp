class Solution {
public:
    void dfs(int i, vector<bool> &vis, vector<vector<int>> &adj){
        if(i < 0 || i >= adj.size() || vis[i]) return;
        vis[i] = true;
        for(int u = 0; u < adj[i].size(); u++){
            if(i != u && adj[i][u] && !vis[u]){
                dfs(u, vis, adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> vis(v, false);
        int ans = 0;
        for(int i = 0; i < v;i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                ans++;
            }
        }
        return ans;
    }
};