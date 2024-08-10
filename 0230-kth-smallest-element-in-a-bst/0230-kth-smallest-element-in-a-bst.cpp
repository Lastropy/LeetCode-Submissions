class Solution {
public:
    int ans;
    void inorder(TreeNode* root, int k, int& curr){
        if(!root || curr == k) return;
        if(root -> left){
            inorder(root -> left, k, curr);
        }
        curr++;
        if(curr == k){
            ans = root -> val;
            return;
        }
        if(root -> right){
            inorder(root -> right, k, curr);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int curr = 0;
        inorder(root, k, curr);
        return ans;
    }
};