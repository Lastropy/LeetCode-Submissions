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
    int ks(TreeNode* root, int k , int &cnt){
        if(!root) return -1;
        int lans = ks(root -> left, k, cnt);
        if(lans != -1) return lans;
        if(cnt == k)
            return root -> val;
        cnt++;
        int rans = ks(root -> right, k , cnt);
        return rans;       
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 1;
        return ks(root, k, cnt);
    }
};