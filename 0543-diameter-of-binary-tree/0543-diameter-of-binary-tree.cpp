
class Solution {
public:
    int findDiameter(TreeNode* root, int &mx){
        if(!root) return 0;
        int lh = findDiameter(root -> left, mx);
        int rh = findDiameter(root -> right, mx);
        mx = max(mx, lh + rh);
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int mx = 0;
        findDiameter(root, mx);
        return mx;
    }
};