class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<pair<int, int>> q;
        int n = g.size(), m = g[0].size(), cntFresh = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 2) q.push({i, j});
                else if(g[i][j] == 1) cntFresh++;
            }
        }
        if(!cntFresh) return 0;
        
        int ans = 0, cntRotten = 0;
        while(!q.empty()){
            ans++;
            int siz = q.size();
            for(int i = 0; i < siz; i++){
                auto tp = q.front(); q.pop();
                int x = tp.first, y = tp.second;
                
                if(x + 1 < n && g[x+1][y] == 1){
                    g[x+1][y] = 2;
                    cntRotten++;
                    q.push({x+1, y});
                }
                
                if(y + 1 < m && g[x][y+1] == 1){
                    g[x][y+1] = 2;
                    cntRotten++;
                    q.push({x, y+1});
                }
                
                if(x - 1 >= 0 && g[x-1][y] == 1){
                    g[x-1][y] = 2;
                    cntRotten++;
                    q.push({x-1, y});
                }
                
                if(y - 1 >= 0 && g[x][y - 1] == 1){
                    g[x][y-1] = 2;
                    cntRotten++;
                    q.push({x, y-1});
                }
            }
        }
        if(cntFresh != cntRotten) return - 1;
        return (ans - 1);
    }
};