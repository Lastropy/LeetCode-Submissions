class Solution {
public:
    vector<int> topoSort(int n, vector<vector<int>> &adj){
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
        
        vector<int> ans;
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
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<vector<int>> adj(n);
        for(auto v: preq){
            adj[v[1]].push_back(v[0]);
        }
        auto ans = topoSort(n, adj);
        if(ans.size() < n) return {};
        return ans;
    }
};