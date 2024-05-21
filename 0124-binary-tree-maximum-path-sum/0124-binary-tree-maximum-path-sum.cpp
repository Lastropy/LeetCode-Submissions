class Solution {
public:
    int dfs(TreeNode *root, int &mx){
        if(!root) return 0;
        int left = max(0, dfs(root -> left, mx));        
        int right = max(0, dfs(root -> right, mx));
        mx = max(mx, (left+ right + (root -> val)));
        return (root -> val) + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        dfs(root, mx);
        return mx;
    }
};