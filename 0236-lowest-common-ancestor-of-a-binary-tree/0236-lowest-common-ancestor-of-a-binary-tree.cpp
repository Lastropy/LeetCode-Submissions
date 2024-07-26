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
    bool find(TreeNode* root, TreeNode* p, vector<TreeNode*>& ans){
        if(!root) return false;
        ans.push_back(root);
        if(root == p) return true;
        if(find(root -> left, p, ans)) return true;
        else if(find(root -> right, p, ans)) return true;
        ans.pop_back();
        return false;
    }
    
    TreeNode* LCA(vector<TreeNode*>& p1, vector<TreeNode*>& p2){
        int i = 0;
        while(i < min(p1.size(), p2.size()) && (p1[i] == p2[i])){
            i++;
        }
        
        return p1[i - 1];
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> p1, p2;
        find(root, p, p1);
        find(root, q, p2);
        return LCA(p1, p2);
    }
};