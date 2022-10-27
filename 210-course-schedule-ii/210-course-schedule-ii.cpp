class Solution {
private:    
    vector<int> kahn_topo_sort(vector<vector<int>> &g){
        int n = g.size(), count;
        queue<int> q;
        vector<int> indegree(n, 0), ans;
        
        for(int i = 0; i < n; i++)
            for(auto node : g[i])
                indegree[node]++;
        
        for(int  i = 0; i < n; i++)
            if(!indegree[i])
                q.push(i);
        
        for(count = 0; !q.empty();  ans.push_back(q.front()), q.pop(), count++)
            for(auto node: g[q.front()])
                if(!(--indegree[node])) 
                    q.push(node);

        if(count == n) return ans;
        return {};
    }

 
    
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {

        vector<vector<int>> g(n);
        
        for(int i= 0; i < preq.size(); i++)
            g[preq[i][1]].push_back(preq[i][0]);
       
        return kahn_topo_sort(g);
    }
};