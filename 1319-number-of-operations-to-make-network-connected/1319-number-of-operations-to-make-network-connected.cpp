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
    
    int findUniqueSets(){
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
    int makeConnected(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        int useless = 0;
        for(auto e: edges){
            if(!ds.unionBySize(e[0], e[1])){
                useless++;
            }
        }
        int uniqueSets = ds.findUniqueSets();
        if(useless < uniqueSets - 1) return -1;
        return (uniqueSets - 1);
        
    }
};