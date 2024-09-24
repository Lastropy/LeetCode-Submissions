class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }   
    
    int findUltimateParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }
    
    bool unionBySize(int u, int v){
        int upU = findUltimateParent(u);        
        int upV = findUltimateParent(v);
        if(upU != upV){
            if(size[upU] < size[upV]){
                parent[upU] = upV;
                size[upV] += size[upU];
            } else {
                parent[upV] = upU;
                size[upU] += size[upV];
            }
            return true;
        }
        return false;
    }
};

class Solution {
    bool isValid(int nx, int ny, int n){
        return (nx >= 0 && ny >= 0 && nx < n && ny < n);
    }
public:
    int largestIsland(vector<vector<int>>& g) {
        int n = g.size();
        DisjointSet ds(n*n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j]){
                    int dx[4] = {-1, +1, 0, 0};
                    int dy[4] = {0, 0 , -1, +1};
                    for(int k = 0;k < 4; k++){
                        int nx = i + dx[k], ny = j + dy[k];
                        if(isValid(nx, ny, n) && g[nx][ny]){
                            ds.unionBySize(nx*n + ny, i * n + j);
                        }
                    }
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < ds.size.size(); i++){
            ans = max(ans, ds.size[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!g[i][j]){
                    int dx[4] = {-1, +1, 0, 0};
                    int dy[4] = {0, 0 , -1, +1};
                    int curr = 1;
                    unordered_map<int, int> mp;
                    for(int k = 0;k < 4; k++){
                        int nx = i + dx[k], ny = j + dy[k];
                        if(isValid(nx, ny, n) && g[nx][ny]){
                            int uP = ds.findUltimateParent(nx *n + ny);
                            if(!mp.count(uP)) curr += ds.size[uP];
                            mp[uP] = 1;
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
        
        
    }
};