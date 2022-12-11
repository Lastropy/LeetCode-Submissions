class Solution {
public:
    int dfs(TreeNode* root, int &ans){
        if(!root) return 0;
        
        int curr = root -> val;
        int lmax = dfs(root-> left, ans);
        int rmax = dfs(root -> right, ans);
        
        ans = max({ans , curr, curr + lmax , curr + rmax, curr+ lmax + rmax});
        
        return max({curr, curr + lmax, curr + rmax});
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};