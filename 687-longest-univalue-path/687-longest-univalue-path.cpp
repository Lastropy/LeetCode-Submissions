class Solution {
public:
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        
        int lmax = dfs(root -> left, res);
        int rmax = dfs(root -> right, res);
        
        int curr = 1, ans = 1;
        if(lmax && root -> left -> val == root -> val)
        {
            curr += lmax;
            ans = max(ans, 1 + lmax);           
        }   
        if(rmax && root -> right -> val == root -> val)
        {
            curr += rmax;
            ans = max(ans, 1 + rmax);
        }
        
        res = max(res, curr);
        
        return ans; 
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        dfs(root, ans);        
        return ans-1;
    }
};