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
    Node* dfs(Node *node, unordered_map<int, Node*> &visited){
        if(visited.count(node -> val)) return visited[node -> val];
        auto new_n = new Node(node -> val);
        visited[node -> val] = new_n;
        for(auto nei: node -> neighbors){
            auto cloned_nei = dfs(nei, visited);
            new_n -> neighbors.push_back(cloned_nei);
        }
        return new_n;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        auto ans = new Node(node -> val);
        if(node -> neighbors.empty()) return ans;
        unordered_map<int, Node*> visited;
        ans = dfs(node, visited);
        return ans;
    }
};