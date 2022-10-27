class Solution {
private:    
    vector<int> kahn_topo_sort(vector<vector<int>> &g){
        int n = g.size();
        queue<int> q;
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < n; i++)
            for(auto node : g[i])
                indegree[node]++;
        
        for(int  i = 0; i < n; i++)
            if(!indegree[i])
                q.push(i);
        
        int count = 0;
        vector<int> ans;
        for(; !q.empty(); q.pop(), count++){
            auto u = q.front();
            
            for(auto node: g[u])
                if(!(--indegree[node])) 
                    q.push(node);
            
            ans.push_back(u);
        }

        
        if(count != n) return {};
        return ans;
    }

 
    
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {

        vector<vector<int>> g(n);
        
        for(int i= 0; i < preq.size(); i++)
            g[preq[i][1]].push_back(preq[i][0]);
       
        return kahn_topo_sort(g);
    }
};