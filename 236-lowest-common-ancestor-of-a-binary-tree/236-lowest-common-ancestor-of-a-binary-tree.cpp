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
    static bool path(TreeNode* a, TreeNode* b, vector<TreeNode *> &ans)     {
        if(a == NULL) return false;
        ans.push_back(a);
        if( a -> val  == b -> val) 
            return true;
        if(path(a-> left,b, ans) || path(a-> right,b, ans))
            return true;
        ans.pop_back();
        return false;
    }
    static TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root ==  p || root == q) 
            return root;
        auto l = lca(root -> left,p,q);
        auto r = lca(root -> right,p,q);
        if(l && r) return root;
        if(l) return l;
        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode *> ans1,ans2;
        // path(root,p, ans1);
        // path(root,q, ans2);
        // auto lca = root;
        // for(int i  = 0; i< min(ans1.size(),ans2.size()); i++){
        //     if(ans1[i] == ans2[i]){
        //         lca = ans1[i];
        //     }
        // }
        // return lca;
        return lca(root, p, q);
    }
};