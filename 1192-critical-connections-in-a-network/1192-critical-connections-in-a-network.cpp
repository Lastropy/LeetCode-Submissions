class Solution {
    int timer = 1;
    void dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &time, vector<int> &low_time, vector<vector<int>> &ans){
        if(vis[node]) return;
        vis[node] = true;
        time[node] = low_time[node] = timer++;
        for(auto it: adj[node]){
            if(it == parent) continue;
            dfs(it, node, vis, adj, time, low_time, ans);
            low_time[node] = min(low_time[node], low_time[it]);
            if(low_time[it] > time[node]){
                ans.push_back({it, node});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);            
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> time(n), low_time(n);
        vector<bool> vis(n, false);
        vector<vector<int>> ans;
        dfs(0, -1,vis, adj, time, low_time, ans);
        return ans;
    }
};