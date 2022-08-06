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
    unordered_map<Node*, Node*> visited;
    Node* clone_using_dfs(Node *node){
        if(visited.count(node)) 
            return visited[node];
        
        auto cloned_node = new Node(node -> val);
        visited[node] = cloned_node;
        
        for(auto neighbour: node -> neighbors)
            cloned_node -> neighbors.push_back(clone_using_dfs(neighbour));
        
        return cloned_node;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(node -> neighbors.empty()) return new Node(node -> val);
        
        auto ans = clone_using_dfs(node);
        return ans;
    }
};