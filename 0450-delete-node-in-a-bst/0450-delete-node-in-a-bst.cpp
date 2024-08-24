class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
        } else if(root -> val < key){
            root -> right = deleteNode(root -> right, key);
        } else {
            TreeNode* temp;
            if((root -> left) == NULL || (root -> right) == NULL){
                temp = ((root -> left) ? (root -> left): (root -> right));
                delete root;
                return temp;
            }
            temp = root -> right;
            if(root -> left){
                auto curr = root -> left;
                while(curr -> right){
                    curr = curr -> right;
                }
                curr -> right = temp;
                temp = root -> left;
            }
            delete root;
            return temp;
        }
        return root;
    }
};