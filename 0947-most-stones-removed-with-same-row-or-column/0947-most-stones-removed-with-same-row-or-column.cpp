class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n+1, 1);
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
public:
    int removeStones(vector<vector<int>>& stones) {
        int numOfStones = stones.size();
        int n = 0, m = 0;
        for(auto it: stones){
            m = max(m, it[0]);
            n = max(n, it[1]);
        }
        
        DisjointSet ds(n+m+1);
        unordered_set<int> st;
        for(auto it: stones){
            int rowNode = it[0];
            int colNode = it[1] + m + 1;
            ds.unionBySize(rowNode, colNode);
            st.insert(rowNode);
            st.insert(colNode);
        }
        
        int groups = 0;
        for(auto it: st){
            if(ds.findUltimateParent(it) == it){
                groups++;
            }
        }
        return (numOfStones - groups);
    }
};