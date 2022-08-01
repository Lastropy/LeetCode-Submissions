class Solution {
public:
    bool checkBipartite(vector<vector<int>> &g, int n, vector<int> &colour, int st){
        queue<int> q;
        q.push(st);
        colour[st] = 1;
        // int col = 0;
        while(!q.empty()){
            int temp = q.front(); q.pop();
            for(auto node: g[temp]){
                if(colour[node] == colour[temp])
                    return false;
                if(colour[node] == -1){
                    colour[node] = 1 - colour[temp];
                    q.push(node);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n + 1);
        for(auto d: dislikes){
            int u = d[0];
            int v = d[1];
            
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> colour(n + 1, -1);
        for(int i= 0; i < g.size(); i++){
            if(colour[i] == -1)
                if(!checkBipartite(g, n, colour, i))
                    return false;
        }
        return true;
    }
};