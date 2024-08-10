class Solution {
public:
    bool isValidBST(TreeNode* root, long l = (long)INT_MIN - 1, long h = (long)INT_MAX + 1) {
        if(!root) return true;
        if((root -> val) <= l || (root -> val) >= h) return false;
        
        bool isValidLeft = isValidBST(root -> left, l, root -> val);
        bool isValidRight = isValidBST(root -> right, root -> val, h);
        return (isValidLeft && isValidRight);
    }
};