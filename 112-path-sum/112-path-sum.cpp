/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode *root, int tar){
        if(!root) return false;
        tar -= root -> val;
        if(!(root -> left) && !(root -> right)) return tar == 0;
        
        return f(root -> left, tar) || f (root -> right, tar);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // if(!root) return false;
        return f(root, targetSum);
    }
};