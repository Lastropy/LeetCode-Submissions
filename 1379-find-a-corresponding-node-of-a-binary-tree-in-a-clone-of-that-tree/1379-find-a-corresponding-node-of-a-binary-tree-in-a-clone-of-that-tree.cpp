/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* root, TreeNode* target)     {
        if(root == NULL) return NULL;
        if(original == target) return root;
        auto res = getTargetCopy(original -> left , root-> left, target);
        if(res) return res;
        return getTargetCopy(original -> right, root -> right, target);
    }
};