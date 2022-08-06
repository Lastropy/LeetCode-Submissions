/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> visited;
    Node* clone_using_dfs(Node *node){
        if(visited.count(node -> val)) return visited[node -> val];
        
        auto new_n = new Node(node -> val);
        visited[node -> val] = new_n;
        
        for(auto neighbour: node -> neighbors)
            new_n -> neighbors.push_back(clone_using_dfs(neighbour));
        
        return new_n;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(node -> neighbors.empty()) return new Node(node -> val);
        
        auto ans = clone_using_dfs(node);
        return ans;
    }
};