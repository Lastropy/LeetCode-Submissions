class Solution {
public:
    bool isCycle(vector<vector<int>> &g, vector<int> visited, int st){
        if(visited[st] == 1) return true;
        if(visited[st] == 2) return false;
        visited[st] = 1;
        
        for(auto node: g[st]){
            if(isCycle(g, visited, node))
                return true;
        }
        
        
        visited[st] = 0;
        return false;
    }
    bool cycle(vector<vector<int>> &g){
        vector<int> visited(g.size(), 0);
        
        for(int i = 0; i < g.size() ; i++){
            if(isCycle(g, visited, i)){
                return true;
            }
            else{
                visited[i] = 2;
            }
        }
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>> g(n);
        for(auto p: preq){
            int u = p[0], v= p[1];
            g[u].push_back(v);
        }
        
        return !cycle(g);
        
        
        
    }
};