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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        
        vector<double> ans;
        while(!q.empty()){
            int size = q.size();
            double curr = 0;
            for(int i = 1; i <= size; i++){
                auto temp = q.front(); q.pop();
                curr += temp -> val;
                
                if(temp -> right) q.push(temp -> right);
                if(temp -> left) q.push(temp -> left);
            }
            
            ans.push_back(curr/size);
        }
        
        return ans;
    }
};