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
    // bool path(TreeNode *root, TreeNode *p, vector<TreeNode *> &p1){
    //     if(root == NULL) return false;
    //     p1.push_back(root);
    //     if(root -> val == p -> val)
    //         return true;
    //     else if(path(root -> left, p, p1) || path(root -> right, p ,p1))
    //         return true;
    //     p1.pop_back();
    //     return false;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)  {
        //  // Solution 1 -> by path. General Solution
        // vector<TreeNode *> p1, p2;
        // path(root, p , p1);
        // path(root , q , p2);
        // auto ans = root;
        // for(int i = 0; i < min(p1.size(), p2.size()); i++){
        //     if(p1[i] == p2[i])
        //         ans = p1[i];
        // }
        // return ans;
        
        
        // Solution 2 -> using property of BST
        if(root -> val < p-> val && root -> val < q-> val)
            return lowestCommonAncestor(root -> right, p , q);
        else if( root -> val > p -> val && root -> val > q -> val)
            return lowestCommonAncestor(root -> left, p , q);
        return root;
    }
};