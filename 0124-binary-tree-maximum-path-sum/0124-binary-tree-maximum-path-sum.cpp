class Solution {
public:
    int dfs(TreeNode *root, int &mx){
        if(!root) return 0;
        int left = dfs(root -> left, mx);        
        int right = dfs(root -> right, mx);
        mx = max(mx, ( max(left, 0)+ max(right,0) + (root -> val)));
        return (root -> val) + max({0, left, right});
    }
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        dfs(root, mx);
        return mx;
    }
};