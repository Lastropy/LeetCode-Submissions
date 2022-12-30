class Solution {
public:
    void dfs(vector<vector<int>> &adj, int node, vector<vector<int>> &ans, vector<bool> &vis, vector<int> curr = {0}){
        if(node == adj.size() - 1){
            ans.push_back(curr);
            return;
        }
        if(vis[node]) return;
        vis[node] = true;
        for(auto n: adj[node]){
            if(!vis[n]){
                curr.push_back(n);
                dfs(adj, n, ans, vis, curr);
                curr.pop_back();
            }
        }
        vis[node] = false;
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<bool> vis(graph.size(), false);
        dfs(graph, 0, ans,vis );
        return ans;
    }
};