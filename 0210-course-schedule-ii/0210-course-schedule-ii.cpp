class Solution {
private:
    void dfs(vector<vector<int>> &g, int idx , vector<bool> &visited, stack<int> &st){
        int n = g.size();
        if(idx == n) return;
        if(visited[idx]) return;
        visited[idx] = 1;
        for(auto node: g[idx]){
            if(!visited[node])
                dfs(g, node, visited, st);
        }
        st.push(idx);
    }
    
    vector<int> topo_sort(vector<vector<int>> &g, vector<bool> &visited, stack<int> &st){
        int n = g.size();
        for(int i = 0; i < n; i++){
            if(!visited[i])
                dfs(g, i, visited, st);
        }
          
        vector<int> ans;
        while(!st.empty())
            ans.push_back(st.top()), st.pop();
        return ans;
        
    }
    bool cycleDFS(vector<vector<int>> &g, int idx, vector<int> &visited){
        int n = g.size();
        if(idx == n) return false;
        if(visited[idx] == 2) return false;
        if(visited[idx] == 1) return true;
        
        visited[idx] = 1;
        for(auto node: g[idx]){
            if(cycleDFS(g, node, visited))
                return true;
        }
        visited[idx] = 0;
        return false;
    }

    bool cycleDetect(vector<vector<int>> &g){
        int n = g.size();
        vector<int> visited(n, 0);
        
        for(int i = 0; i < n; i++){
            if(cycleDFS(g, i, visited))
                return true;
            else visited[i] = 2;
        }
        return false;  
    }
    
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {

        vector<vector<int>> g(n);
        for(int i= 0; i < preq.size(); i++){
            int u = preq[i][1], v = preq[i][0];
            g[u].push_back(v);
        }
        
        
        if(cycleDetect(g)) return {};
        
        vector<bool> visited(n, false);
        stack<int> helperStack;
        
        return topo_sort(g, visited, helperStack);
    }
};