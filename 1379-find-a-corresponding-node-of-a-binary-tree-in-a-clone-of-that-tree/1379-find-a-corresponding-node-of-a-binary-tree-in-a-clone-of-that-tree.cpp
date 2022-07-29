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
        if(root -> val == target -> val) return root;
        auto res = getTargetCopy(original , root-> left, target);
        if(res) return res;
        return getTargetCopy(original, root -> right, target);
    }
};