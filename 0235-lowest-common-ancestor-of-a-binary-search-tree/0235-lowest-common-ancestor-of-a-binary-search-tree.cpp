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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        bool isLesser1 = (p -> val) < (root -> val);
        bool isLesser2 = (q -> val) < (root -> val);
        if(isLesser1 == isLesser2){
            if(isLesser1){
                return lowestCommonAncestor(root -> left, p, q);
            } else {
                return lowestCommonAncestor(root -> right, p, q);
            }
        }
        return root;
    }
};