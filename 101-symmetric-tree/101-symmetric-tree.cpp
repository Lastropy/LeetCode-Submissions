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
    bool sym(TreeNode *a, TreeNode *b){
        if(a == NULL && b == NULL) return true;
        if(a == NULL || b == NULL) return false;
        bool cond = a -> val == b -> val;
        return cond && sym(a-> left, b -> right) && sym(a-> right, b -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return sym(root-> left, root-> right);
    }
};