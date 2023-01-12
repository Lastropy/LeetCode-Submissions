class Solution {
public:
    
    vector<int> dfs(int node, vector<bool> &vis, vector<vector<int>> &g, string &labels, vector<int> &ans){
        if(vis[node]) return {};
        
        vis[node] = true;
        vector<int> freq(26, 0);
        for(auto nodes: g[node]){
            auto temp = dfs(nodes,vis, g, labels, ans);
            for(int i = 0; i < temp.size(); i++)
                freq[i] += temp[i];
        }
        
        ans[node] = freq[labels[node] - 'a'] + 1;
        freq[labels[node] - 'a']++;
        vis[node] = false;
        return freq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for(auto v: edges)
        {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<bool> vis(n, false);
        vector<int> ans(n, -1);
        dfs(0, vis, g, labels, ans);
        return ans;
        
    }
};