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
    TreeNode* build(vector<int> &preo, int &i, long ub){
        if(i == preo.size() || preo[i] > ub) return NULL;
        auto root = new TreeNode(preo[i++]);
        root -> left = build(preo, i , root -> val);
        root -> right = build(preo, i , ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preo) {
        int i = 0;
        return build(preo, i, INT_MAX);
    }
};