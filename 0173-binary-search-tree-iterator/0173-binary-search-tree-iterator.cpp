class BSTIterator {
private:
    stack<TreeNode *> st;
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root -> left;
        }
    }
    
    int next() {
        auto tp = st.top(); st.pop();
        int ans = tp -> val;
        tp = tp -> right;
        while(tp){
            st.push(tp);
            tp = tp -> left;
        }
        return ans;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */