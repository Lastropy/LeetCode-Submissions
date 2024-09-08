class Solution {
public:
    bool checkBipartite(vector<vector<int>> &g, vector<int> &col, int i){
        queue<int> q;
        col[i] = 1;
        q.push(i);
        while(!q.empty()){
            auto temp = q.front(); q.pop();
            for(auto u: g[temp]){
                if(col[u] == col[temp]) return false;
                if(col[u] == -1){
                    q.push(u);
                    col[u] = !col[temp];
                } 
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> col(n, -1);
        for(int i = 0; i < n; i++){
            if(col[i] == -1 && !checkBipartite(g, col, i))
                return false;
        }
        return true;
    }
};