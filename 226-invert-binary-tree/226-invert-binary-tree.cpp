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
    TreeNode* invertTree(TreeNode* root) {
        // Iterative soln -> 1 stack
        // TC -> O(n) 
        // SC -> O(n)
        if(root == NULL) return root;
        stack<TreeNode *> st;
        st.push(root);
        auto curr = root;
        while(!st.empty()){
            auto temp = st.top();
            st.pop();
            swap(temp -> right, temp -> left);
            if(temp -> left) st.push(temp -> left);
            if(temp -> right) st.push(temp -> right);
        }
        return root;
        
        
        
        //  // Recursive approach
        // // TC -> O(n) 
        // // SC -> O(n)
        // if(root == NULL) return root;
        // root -> left = invertTree(root -> left);
        // root -> right = invertTree(root -> right);
        // auto temp = root -> left;
        // root -> left = root -> right;
        // root -> right = temp;
        // return root;
    }
};