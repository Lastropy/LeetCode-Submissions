class DisjointSet{
vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n, 1);
    }   
    
    int findUltimateParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }
    
    int numberOfConnectedComponents(){
        int ans = 0;
        for(int i = 0; i < parent.size(); i++){
            ans += (parent[i] == i);
        }
        return ans;
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
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int v = adj.size();
        DisjointSet ds(v);
        for(int i = 0; i < v;i++){
            for(int j = 0; j < v; j++){
                if(adj[i][j]){
                    ds.unionBySize(i, j);
                }
            }
        }
        
        return ds.numberOfConnectedComponents();
    }
};