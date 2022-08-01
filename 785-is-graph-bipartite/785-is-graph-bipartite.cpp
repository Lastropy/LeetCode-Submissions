class Solution {
public:
    bool checkBipartite(vector<vector<int>> &g, vector<int> &colour, int st){
        if(colour[st] != -1) return true;
        
        queue<int> q;
        colour[st] =1;
        for(q.push(st); !q.empty(); q.pop()){
            auto temp = q.front();
            for(auto node: g[temp]){
                if(colour[node] == colour[temp])
                    return false;
                if(colour[node] == -1){
                    q.push(node);
                    colour[node] = 1-colour[temp];
                } 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(!checkBipartite(graph, colour, i))
                return false;
        }
        return true;
    }
};