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
    int height(TreeNode* root, bool goLeft){
        if(!root) return 0;
        if(goLeft) return 1 + height(root -> left, goLeft);
        return 1 + height(root -> right, goLeft);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = height(root, 1);
        int rh = height(root, 0);
        if(lh == rh) return (1 << lh) - 1;
        return (1 + countNodes(root -> left) + countNodes(root -> right));
    }
};