class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &g) {
        int m = g.size(), n = g[0].size();
        using vi = vector<int>;
        set<vi> st;
        vector<vi> dist(m, vi(n, 1e9));
        st.insert({0, 0, 0});
        dist[0][0] = 0;
        
        int dx[4] = {-1, +1, 0, 0};
        int dy[4] = {0, 0, +1, -1};
        while(!st.empty()){
            auto tp = *(st.begin());
            st.erase(tp);
            int cost = tp[0], x = tp[1], y = tp[2];
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                    int MAD = max(cost, abs(g[nx][ny] - g[x][y]));
                    if(dist[nx][ny] > MAD){
                        if(dist[nx][ny] != 1e9){
                            st.erase({dist[nx][ny], nx, ny});
                        }
                        dist[nx][ny] = MAD;
                        st.insert({dist[nx][ny], nx, ny});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};