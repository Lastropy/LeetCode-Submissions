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
    void f(TreeNode *root, int lvl ,vector<vector<int>> &ans){
        if(!root) return;
        if(ans.size() == lvl) ans.push_back(vector<int>());
        ans[lvl].push_back(root -> val);
        f(root -> left, lvl+1, ans);
        f(root -> right, lvl + 1, ans );
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        f(root, 0, ans);
        return ans;
        // vector<vector<int>> ans;
        // if(!root) return ans;
        // queue<pair<TreeNode *, int>> q;
        // auto now = 0;
        // q.push({root,now});
        // while(!q.empty()){
        //     vector<int> e;
        //     auto temp = q.front();
        //     while(!q.empty() && temp.second == now){
        //         e.push_back(temp.first -> val);
        //         q.pop();
        //         if(temp.first -> left)
        //             q.push({temp.first -> left,now+1});
        //         if(temp.first -> right)
        //             q.push({temp.first -> right, now+1});
        //         temp = q.front();
        //     }
        //     now++;
        //     ans.push_back(e);
        // }
        // return ans;
    }
};