class Solution {
public:
    TreeNode* arrange(TreeNode* root, TreeNode* tail = NULL){
        if(!root) return tail;
        
        auto res = arrange(root -> left, root);
        root -> left = NULL;
        root -> right = arrange(root -> right, tail);
        return res;
    }
    TreeNode* increasingBST(TreeNode* root) {
        return arrange(root);
    }
};