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
    void goLeft(TreeNode* root, vector<int> &ans, int lvl = 0){
        if(!root) return;
        if(ans.size() == lvl) {
            ans.push_back(root -> val);
        }
        goLeft(root -> right, ans, lvl+1);
        goLeft(root -> left, ans, lvl + 1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        goLeft(root, ans);
        return ans;
    }
};