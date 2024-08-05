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
    vector<int> postorderTraversal(TreeNode* root) {
        // Left Right Root
        vector<int> ans;
        if(!root) return ans;
        auto curr = root;
        
        while(curr){
            if(curr -> right){
                auto prev = curr -> right;
                while(prev -> left && prev -> left != curr){
                    prev = prev -> left;
                }
                if(prev -> left){
                    prev -> left = NULL;
                    curr = curr -> left;
                } else {
                    prev -> left = curr;
                    ans.push_back(curr -> val);
                    curr = curr -> right;
                }
            } else {
                ans.push_back(curr -> val);
                curr = curr -> left;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};