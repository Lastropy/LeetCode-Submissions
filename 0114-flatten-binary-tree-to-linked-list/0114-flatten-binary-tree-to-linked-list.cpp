class Solution {
public:
    void flatten(TreeNode* node) {
        if(!node) return;
        TreeNode *prev = NULL, *curr = node;
        while(curr){
            if(curr -> left){
                prev = curr -> left;
                while(prev -> right)
                    prev = prev -> right;
                prev -> right = curr -> right;
                curr -> right = curr -> left;
                curr -> left = NULL;
            }
            curr = curr -> right;
        }
    }
};