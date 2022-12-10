class Solution {
public:
    TreeNode* ans;
    void arrange(TreeNode* root){
        if(!root) return;
        
        arrange(root -> left);
        root -> left = NULL;
        ans -> right = root;
        ans = ans -> right;
        arrange(root -> right);
        
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        ans = new TreeNode();
        auto ans2 = ans;
        arrange(root);
        return ans2 -> right;
    }
};