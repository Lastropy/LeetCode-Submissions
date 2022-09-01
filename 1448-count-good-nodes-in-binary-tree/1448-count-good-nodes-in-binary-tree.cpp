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
    void f(TreeNode* root, int &ans, int msf){
        if(root == NULL) return;

        if( root -> val >= msf)
            ans++;
        msf = max(root -> val, msf);

        f(root -> left, ans, msf);
        f(root -> right, ans , msf);
        
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int msf = INT_MIN;
        f(root, ans, msf);
        return ans;
    }
};