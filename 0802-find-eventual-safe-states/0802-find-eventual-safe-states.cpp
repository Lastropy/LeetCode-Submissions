class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> ans;
        vector<int> indeg(n, 0);
        for(int i = 0; i < n; i++){
            for(auto u: adj[i]){
                indeg[u]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            auto tp = q.front(); q.pop();
            ans.push_back(tp);
            for(auto u: adj[tp]){
                indeg[u]--;
                if(indeg[u] == 0){
                    q.push(u);
                } 
            }
        }
        return ans;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<int>> adj(n);
        
        // inverted graph
        for(int i = 0; i < n; i++){
            for(auto u: g[i]){
                adj[u].push_back(i);
            }
        }
        
        auto ans = topoSort(n, adj);
        sort(ans.begin(), ans.end());
        return ans;
    }
};