class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n , -1));
        
        queue<vector<int>> q;
        
        for(q.push({0, 0 , k, 0}); !q.empty(); q.pop() ){
            auto t = q.front();
            int x = t[0], y =  t[1];
            
            if(x < 0 || y < 0 || x >= m || y >= n) 
                continue;
            
            if(x == m - 1 && y == n - 1)
                return t[3];
            
            if(grid[x][y]){
                if(t[2] > 0) t[2]--;
                else continue;
            }
            
            if(vis[x][y] != -1 && vis[x][y] >= t[2])
                continue;
            vis[x][y] = t[2];
            
            q.push({x+1, y, t[2], t[3] + 1});
            q.push({x, y+1, t[2], t[3] + 1});
            q.push({x-1, y, t[2], t[3] + 1});
            q.push({x, y-1, t[2], t[3] + 1});
        }
        
        return -1;
    }
};