class Solution {
public:
    void dfs(vector<vector<int>> &adj, int node, vector<vector<int>> &ans, vector<int> curr = {0}){
        if(node == adj.size() - 1){
            ans.push_back(curr);
            return;
        }
        for(auto n: adj[node]){
            curr.push_back(n);
            dfs(adj, n, ans, curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        dfs(graph, 0, ans);
        return ans;
    }
};