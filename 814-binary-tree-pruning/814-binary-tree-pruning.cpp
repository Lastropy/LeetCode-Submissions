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
    bool hasOne(TreeNode *root){
        if(!root) return false;
        
        bool leftHas1 = hasOne(root -> left);
        
        bool rightHas1 = hasOne(root -> right);
        
        if(!leftHas1) root -> left = NULL;
        if(!rightHas1) root -> right = NULL;
        
        return (leftHas1 || rightHas1 || root -> val);
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!root) return root;
        
        if(!hasOne(root)) root = NULL;
        
        return root;
    }
};