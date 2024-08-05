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
    TreeNode* preo(TreeNode* root){
        if(root == NULL) return NULL;
        auto l = preo(root -> left);
        auto r = preo(root -> right);
        root -> left = NULL;
        root -> right = l;
        auto curr = root;
        while(curr -> right){
            curr = curr -> right;
        }
        curr -> right = r;
        return root;
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        preo(root);
    }
};