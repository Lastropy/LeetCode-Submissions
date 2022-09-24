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
    void f(TreeNode *root, int tar, vector<int> temp, vector<vector<int>> &ans){
        if(!root){ return;}
        
        tar -= root -> val;
        temp.push_back(root->val);
        
        if(!root -> left && !root -> right){
            if(tar == 0)
                ans.push_back(temp);
        }
        

        f(root -> left, tar, temp, ans);
        f(root -> right, tar,temp, ans);
     }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(root, targetSum, temp, ans);
        return ans;
        
    }
};