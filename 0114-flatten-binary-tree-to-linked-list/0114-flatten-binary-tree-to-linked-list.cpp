class Solution {
private:
    stack<TreeNode *> st;
public:
    void flatten(TreeNode* node) {
        if(!node) return;
        st.push(node);
        while(!st.empty()){
            auto curr = st.top(); st.pop();
            if(curr -> right) st.push(curr -> right);
            if(curr -> left) st.push(curr -> left);
            if(!st.empty()) curr -> right = st.top();
            curr -> left = NULL;
        }
    }
};