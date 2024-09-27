class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* clone_using_dfs(Node *node){
        if(visited.count(node)) return visited[node];
        if(node == NULL) return NULL;
        auto cloned_node = new Node(node -> val);
        visited[node] = cloned_node;
        for(auto neighbour: node -> neighbors)
            cloned_node -> neighbors.push_back(clone_using_dfs(neighbour));
        return cloned_node;
    }
    Node* cloneGraph(Node* node) {
        return clone_using_dfs(node);
    }
};