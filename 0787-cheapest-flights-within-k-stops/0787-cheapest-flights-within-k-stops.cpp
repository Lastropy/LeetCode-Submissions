class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<pair<int, int>> adj[n];
        for(auto f: flights){
            adj[f[0]].push_back({f[1], f[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,src});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(!pq.empty()){
            auto tp = pq.top(); pq.pop();
            int node = tp[2], stops = tp[0], cost = tp[1];
            if(stops <= k){
                for(auto u: adj[node]){
                    if(dist[u.first] > cost + u.second){
                        dist[u.first] = cost + u.second;
                        pq.push({stops+1, dist[u.first], u.first});
                    }
                }
            }
        }
        if(dist[dest] == 1e9) return -1;
        return dist[dest];
    }
};