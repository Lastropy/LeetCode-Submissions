class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // modified Dijkstra
        // How? Whenever you reach dest, 
        // if dist[dest] > curr_dist => Reset counter to 1
        // if dist[dest] == curr_dist => Inc Counter by 1
        // if dist[dest] < curr_dist => ignore;
        int MOD = 1e9 + 7;
        vector<pair<int, int>> adj[n];
        for(auto r: roads){
            adj[r[0]].push_back({r[1], r[2]});            
            adj[r[1]].push_back({r[0], r[2]});
        }
        
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);        
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            auto tp = pq.top(); pq.pop();
            int node = tp.second;
            long long curr_dist = tp.first;
            for(auto u: adj[node]){
                if(dist[u.first] > curr_dist + u.second){
                    ways[u.first] = ways[node];
                    dist[u.first] = curr_dist + u.second;
                    pq.push({dist[u.first], u.first});
                } else if(dist[u.first] == curr_dist + u.second){
                    ways[u.first] = (ways[u.first] + ways[node]) % MOD;
                } 
            }
        }
        return (ways[n-1] % MOD);
     }
};