class Solution {
public:
    int dfs(TreeNode *root, int &ans){
        if(!root) return 0;
        
        int lmax = dfs(root -> left, ans);
        int rmax = dfs(root -> right, ans);
        
        ans = max(ans, lmax + rmax);
        
        return 1 + max(lmax, rmax);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(root) dfs(root,ans);
        return ans ;
    }
};