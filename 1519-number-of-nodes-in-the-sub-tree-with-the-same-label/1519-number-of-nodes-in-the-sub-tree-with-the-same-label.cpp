class Solution {
public:
    
    vector<int> dfs(int node, vector<vector<int>> &g, string &labels, vector<int> &ans){
        if(ans[node]) return {};
        
        vector<int> freq(26, 0);
        ans[node] = freq[labels[node]-'a'] = 1;
        
        for(auto nodes: g[node]){
            auto temp = dfs(nodes, g, labels, ans);
            for(int i = 0; i < temp.size(); i++)
                freq[i] += temp[i];
        }
        
        ans[node] = freq[labels[node] - 'a'];
        return freq;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for(auto v: edges)
        {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        vector<int> ans(n, 0);
        dfs(0, g, labels, ans);
        return ans;
        
    }
};