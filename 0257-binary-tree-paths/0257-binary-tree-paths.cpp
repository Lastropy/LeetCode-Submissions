
class Solution {
public:
    void dfs(TreeNode* root, vector<string> &ans, string curr=""){
        if(!root){
            return;
        }
        
        if(curr != "") curr += "->";
        curr += to_string(root -> val);
        if(!root -> left && !root -> right) ans.push_back(curr);
        dfs(root -> left, ans, curr);
        dfs(root -> right, ans, curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return {};
        dfs(root, ans);
        return ans;
    }
};