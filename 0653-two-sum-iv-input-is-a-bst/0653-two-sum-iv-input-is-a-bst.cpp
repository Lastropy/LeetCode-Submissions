class BSTIterator{
private:
    stack<TreeNode *> st;
    bool reverse;
public:
    BSTIterator(TreeNode *root, string state){
        if(!root) return;
        if(state == "before") reverse = true;
        else reverse = false;
        while(root){
            st.push(root);
            if(reverse) root = root -> right;
            else root = root -> left;
        }
    }
    
    bool hasEle(){
        return !st.empty();
    }
    
    int nextEle(){
        auto tp = st.top(); st.pop();
        int ans = tp -> val;
        if(reverse) tp = tp -> left;
        else tp = tp -> right;
        while(tp){
            st.push(tp);
            if(reverse) tp = tp -> right;
            else tp = tp -> left;
        }
        return ans;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        auto st = BSTIterator(root, "next");
        auto en = BSTIterator(root, "before");
        int p = st.nextEle(), q = en.nextEle();
        while(st.hasEle() && en.hasEle()){
            cout << p << " | " << q << endl;
            if(p >= q || p + q == k) break;
            if(p + q < k) p = st.nextEle();
            else q = en.nextEle();
        }
        return ((p < q) && (p + q == k));
    }
};