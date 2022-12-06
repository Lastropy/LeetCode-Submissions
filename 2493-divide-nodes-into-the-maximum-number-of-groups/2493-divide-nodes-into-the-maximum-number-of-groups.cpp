class Solution {
public:
    bool checkBipartite(int src,  vector<int> &colour, vector<vector<int>> &adj, vector<int> &components){
        queue<int> q;
        int n = adj.size();
        colour[src] = 0;
        
        for(q.push(src); !q.empty();){
            int size = q.size();
            for(int i =0; i < size; i++){
                int u = q.front();
                q.pop();
                components[u] = src;
                
                for(auto node: adj[u]){
                    if(colour[node] == -1){
                        colour[node] = 1 - colour[u];
                        q.push(node);
                    }
                    else if(colour[node] == colour[u])
                        return false;
                }
            }
        }
        return true;
    }
    
    int bfs(vector<vector<int>> &adj, int src){
        int n = adj.size();
        
        queue<int> q;
        int count = 0;
        
        vector<bool> vis(n, false);
        vis[src] = true;
        
        for(q.push(src); !q.empty(); count++){
            int size = q.size();
            for(int i = 0; i< size; i++){
                int u =q.front();
                q.pop();
                for(auto node: adj[u]){
                    if(!vis[node]){
                        q.push(node);
                        vis[node] = true;
                    }
                }
            }
        }
        return count;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> components(n, -1), colour(n, -1);
        
        
        for(auto e: edges)
            adj[e[0]-1].push_back(e[1]-1), adj[e[1]-1].push_back(e[0]-1);
        
        for(int i =0; i < n; i++)
            if(colour[i] == -1 && (!checkBipartite(i, colour, adj, components)))
                return -1;
        
        vector<int> comparison(n, 0);
        
        for(int i = 0; i < n; i++)
            comparison[components[i]] = max(comparison[components[i]], bfs(adj, i));
        
        int ans = 0;
        for(int i: comparison)
            ans += i;
        return ans;
    }
};