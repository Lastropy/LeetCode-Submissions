class Solution {
public:
    void inorder(TreeNode* root, vector<int> &li){
        if(!root) return;
        if((!root -> left) && (!root -> right)){
            li.push_back(root -> val);
            return;
        }
        inorder(root -> left, li);
        inorder(root -> right, li);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> li1, li2;
        inorder(root1, li1);
        inorder(root2, li2);
        if(li1.size() != li2.size()) return false;
        return li1 == li2;
    }
};