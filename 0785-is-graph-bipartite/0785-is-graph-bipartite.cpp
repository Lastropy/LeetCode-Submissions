class Solution {
public:
    bool checkBipartite(vector<vector<int>> &g, vector<int> &col, int i, int curr){
        if(col[i] != -1) return (col[i] == curr);
        
        col[i] = curr;
        for(auto u: g[i]){
            if(col[u] == curr) return false;
            else if(col[u] == -1 && !checkBipartite(g, col, u, !curr)){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> col(n, -1);
        for(int i = 0; i < n; i++){
            // cout <<"Hi "<< i << endl;
            if(col[i] == -1 && !checkBipartite(g, col, i, 1)){
                // cout <<"Hello "<<  i<< endl;
                return false;
            }
        }
        return true;
    }
};