class Solution {
private: 
    TreeNode *prev = NULL, *first = NULL, *sec = NULL;
public:
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root -> left);
        if(prev && (prev -> val) >= (root -> val)) {
            if(!first) first = prev;
            sec = root;
        }
        prev = root;
        inorder(root -> right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first && sec) swap(first -> val, sec -> val);
    }
};