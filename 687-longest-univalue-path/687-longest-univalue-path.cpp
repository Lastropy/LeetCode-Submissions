class Solution {
public:
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        
        int lmax = dfs(root -> left, res);
        int rmax = dfs(root -> right, res);
        
        int cl = 0,cr = 0;
        if(root -> left && root -> left -> val == root -> val)
            cl = lmax + 1;         
        if(root -> right && root -> right -> val == root -> val)
            cr = rmax + 1;
        
        res = max(res, cl + cr);
        
        return max(cl, cr); 
    }
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        if(root) dfs(root, ans);        
        return ans;
    }
};