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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(mp.count(email)){
                    ds.unionBySize(mp[email], i);
                } else {
                    mp[email] = i;  
                }
            }
        }
        
        vector<vector<string>> ans;
        vector<int> ansIndex(n, -1);
        for(auto [k, v]: mp){
            int up = ds.findUltimateParent(v);
            if(ansIndex[up] == -1){
                ansIndex[up] = ans.size();
                ans.push_back({accounts[up][0]});
            }
            ans[ansIndex[up]].push_back(k);
        }
        
        for(int i = 0; i < ans.size(); i++){
            sort(ans[i].begin()+1, ans[i].end());
        }
        return ans;
    }
};