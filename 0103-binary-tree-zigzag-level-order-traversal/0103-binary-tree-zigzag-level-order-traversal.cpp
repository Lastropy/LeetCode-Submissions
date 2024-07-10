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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            int siz = q.size();
            vector<int> curr;
            for(int i = 0; i < siz; i++){
                auto tmp = q.front(); q.pop();
                if(tmp -> left) q.push(tmp -> left);
                if(tmp -> right) q.push(tmp -> right);
                curr.push_back(tmp -> val);
            }
            if(lvl % 2) reverse(curr.begin(), curr.end());
            lvl++;
            ans.push_back(curr);
        }
        return ans;
    }
};