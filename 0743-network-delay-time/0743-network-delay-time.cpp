class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }
        vector<long long> dist(n+1,LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty()){
            auto tp = pq.top(); pq.pop();
            int node = tp.second;
            long long curr_dist = tp.first;
            for(auto u: adj[node]){
                int child = u.first, edW = u.second;
                if(dist[child] > curr_dist + edW){
                    dist[child] = curr_dist + edW;
                    pq.push({dist[child], child});
                }
            }
        }
        long long ans = 0;
        for(int i = 1; i < dist.size(); i++){
            if(dist[i] == LLONG_MAX) {
                return -1;
            }
            ans = max(dist[i] , ans);
        }
        return ans;
    }
};