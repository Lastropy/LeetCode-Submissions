class Solution {
private:
    int dfs(TreeNode* root, int cur = 0) {
        if(!root) return 0;
        cur = cur * 10 + root -> val;                 
        if(!root -> left && !root -> right)           
            return cur;
        return dfs(root -> left, cur) + dfs(root -> right, cur); 
    }  
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root);
    }

};