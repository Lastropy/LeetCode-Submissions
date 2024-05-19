class Solution {
public:
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int lh = maxDepth(root -> left);
        int rh = maxDepth(root -> right);
        if(lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
        return 1 + max(lh, rh);
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int ans = maxDepth(root);
        return (ans != -1);
    }
};