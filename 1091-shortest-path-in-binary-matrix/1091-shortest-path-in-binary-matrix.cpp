class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        using vi = vector<int>;
        int n = g.size();
        if(g[0][0] == 1 || g[n-1][n-1] == 1) return -1;
        vector<vi> dist(n, vi(n, INT_MAX));
        dist[0][0] = 1;
        queue<vi> q;
        q.push({1,0,0});
        while(!q.empty()){
            auto tp = q.front(); q.pop();
            int x = tp[1], y = tp[2], cost = tp[0];
            if(x == n-1 && y == n-1) return cost;
            int dx[8] = {-1,+1,0,0,-1,-1,+1,+1};
            int dy[8] = {0,0,-1,+1,-1,+1,-1,+1};
            for(int i = 0; i < 8; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >=0 && ny < n && g[nx][ny] == 0){
                    if(dist[nx][ny] > dist[x][y] + 1){
                        dist[nx][ny]  = dist[x][y] + 1;
                        q.push({dist[nx][ny], nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};