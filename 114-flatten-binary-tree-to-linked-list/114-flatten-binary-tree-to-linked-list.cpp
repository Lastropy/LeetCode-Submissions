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
    void preo(TreeNode* root, vector<TreeNode *> &pr){
        if(root == NULL)
            return;
        pr.push_back(root);
        if(root -> left) preo(root -> left, pr);
        if(root -> right) preo(root -> right, pr);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        vector<TreeNode *> pr;
        preo(root, pr);
        auto ans = new TreeNode(0);
        auto dummy = ans;
        for(auto node: pr){
            ans -> right = node;
            ans -> left = NULL;
            ans = ans -> right;
        }
        ans -> right = ans -> left = NULL;
        root = dummy -> right;
        return;
    }
};