class Solution {
private:
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* node) {
        if(!node) return;
        flatten(node -> right);
        flatten(node -> left);
        node -> right = prev;
        node -> left = NULL;
        prev = node;
        return;
    }
};