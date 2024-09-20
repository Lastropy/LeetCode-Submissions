class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(n, vector<int>(n, 1e9));
        for(auto e: edges){
            adj[e[0]][e[1]] = e[2];
            adj[e[1]][e[0]] = e[2];
        }
        for(int i = 0; i < n; i++){
            adj[i][i] = 0;
        }
        
        for(int via = 0; via < n; via++){
            for(int i =0 ; i < n; i++){
                for(int j = 0; j < n; j++){
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
        
        int ans = 0, mn = INT_MAX;
        for(int i =0; i < n; i++){
            int curr = 0;
            for(int j = 0; j < n; j++){
                if(adj[i][j] <= k){
                    curr++;
                }
            }
            if(curr <= mn){
                mn = curr;
                ans = i;
            }
        }
        return ans;
    }
};