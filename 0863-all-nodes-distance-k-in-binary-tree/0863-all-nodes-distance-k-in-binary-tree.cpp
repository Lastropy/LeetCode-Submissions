class Solution {
public:
    bool findPath(TreeNode *root, TreeNode *t, vector<TreeNode* > &p){
        if(!root) return false;
        p.push_back(root);
        if(root == t) return true;
        else if(findPath(root -> left, t, p)) return true;        
        else if(findPath(root -> right, t, p)) return true;
        p.pop_back();
        return false;
    }
    
    void findKDown(TreeNode *t, int k, vector<int> &ans, TreeNode *last){
        if(!t || k < 0 || t == last) return;
        if(k == 0) ans.push_back(t -> val);
        findKDown(t -> left, k - 1, ans, last);        
        findKDown(t -> right, k - 1, ans, last);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        vector<int> ans;
        vector<TreeNode *> path;
        findPath(root, t, path);
        TreeNode *last = NULL;
        for(int i = path.size() - 1; i >= 0 && k >= 0; i--, k--){
            findKDown(path[i], k, ans, last);
            last = path[i];
        }
        return ans;
    }
};