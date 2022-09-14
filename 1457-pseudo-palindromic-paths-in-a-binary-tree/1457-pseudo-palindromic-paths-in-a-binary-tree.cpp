class Solution {
public:
    int f(TreeNode *root, vector<int> &path){
        if(!root) return 0;
        
        path[root -> val]++;
       
        int ans = 0;
        
        if(root -> left == NULL && root -> right == NULL){
            for(int freq: path)
                ans += (freq % 2);
            
            ans = (ans <= 1);
        }
        ans += f(root -> left, path) + f(root -> right, path);

        path[root -> val]--;

        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {

        vector<int> path(10, 0);
        return f(root, path);

    }
};