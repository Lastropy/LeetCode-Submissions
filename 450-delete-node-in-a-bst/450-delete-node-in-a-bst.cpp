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
    void insert(TreeNode *curr, TreeNode* node){
        if(node == NULL || curr == NULL) return;
        while(true){
            if(curr -> val == node -> val)
                break;
            else if(curr -> val > node -> val){
                if(curr -> left) curr = curr -> left;
                else{curr -> left = node; break;}
            }
            else{
                if(curr -> right) curr = curr -> right;
                else{curr -> right = node; break;}
            }
        }   
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root -> val == key) {
            auto temp = root;
            if(root -> right){
                if(root -> left){
                    auto curr = root -> right;
                    auto node = root -> left;
                    insert(curr,node);
                }
                root = root -> right;
            }
            else
                root = root -> left;
            delete temp;
        }
        else if(root -> val < key){
            root -> right = deleteNode(root -> right, key);
        }
        else if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
        }
        return root;
    }
};