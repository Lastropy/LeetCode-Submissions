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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        // Morris Traversal
        
        TreeNode *curr = root;
        while(curr){
            if(curr -> left == NULL){
                ans.push_back(curr -> val);
                curr= curr -> right;
            }
            else{
                auto prev = curr -> left;
                while(prev -> right && prev -> right != curr)
                    prev = prev -> right;
                if(prev -> right == NULL){
                    prev -> right = curr;
                    curr = curr -> left;
                }
                else{
                    prev -> right = NULL;
                    ans.push_back(curr -> val);
                    curr = curr -> right;                    
                }
            }
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//          //recursive soln        
//         if(root == NULL)
//             return vector<int>();
//         inorderTraversal(root -> left);
//         ans.push_back(root -> val);
//         inorderTraversal(root -> right);
//         return ans;
        
     // // stack iterative
     //    auto curr = root;
     //    stack<TreeNode *> st;
     //    while(true){
     //        if(curr){
     //            st.push(curr);
     //            curr = curr -> left; 
     //        }
     //        else{
     //            if(st.empty()) break;
     //            auto temp = st.top();
     //            st.pop();
     //            ans.push_back(temp -> val);
     //            curr = temp -> right;
     //        }
     //    }
     //    return ans;
        
    // // one pass
    //     if(root == NULL)
    //          return vector<int>();
    //     auto curr = root;
    //     stack<pair<TreeNode*,int>> st;
    //     st.push({curr,1});
    //     while(!st.empty()){
    //         auto temp = st.top();
    //         st.pop();
    //         if(temp.second == 1)
    //         {
    //             temp.second++;
    //             st.push(temp);
    //             if(temp.first -> left)
    //                 st.push({temp.first -> left,1});
    //         }
    //         else{
    //             temp.second++;
    //             ans.push_back(temp.first -> val);
    //             if(temp.first -> right)
    //                 st.push({temp.first -> right,1});
    //         }
    //     }
    //     return ans;
        
    }
};