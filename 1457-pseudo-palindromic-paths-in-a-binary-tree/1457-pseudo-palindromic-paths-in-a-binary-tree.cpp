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
    int f(TreeNode *root, vector<int> path){
        if(!root) return 0;
        path[root -> val]++;
        if(root -> left == NULL && root -> right == NULL){
            int count = 0;
            for(int i = 0; i < 10; i++)
                count += (path[i] % 2);
            return (count <= 1);
        }
        int ans = f(root -> left, path) + f(root -> right, path);
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path(10, 0);
        return f(root, path);
    }
};