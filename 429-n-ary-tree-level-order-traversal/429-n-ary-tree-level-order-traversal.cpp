/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
    
        queue<Node *> q;
        vector<vector<int>> ans;
    
        if(!root) return ans;
        
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            for(int i = 0, size = q.size(); i < size; i++, q.pop())
            {
                auto curr= q.front();
                auto child = curr -> children;
                temp.push_back(curr -> val);
                for(auto node: child)
                    q.push(node);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};