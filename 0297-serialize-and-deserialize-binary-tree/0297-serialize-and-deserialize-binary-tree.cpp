class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode *> q;
        q.push(root);
        string ans = "";
        while(!q.empty()){
            int siz = q.size();
            for(int i = 0; i < siz; i++){
                auto tp = q.front(); q.pop();
                if(ans != "") ans += ',';
                if(tp) {
                    ans += to_string(tp -> val);
                    q.push(tp -> left);
                    q.push(tp -> right);
                }
                else ans += "#";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) { 
        if(s.size() == 0) return NULL;
        stringstream inp(s);
        string curr;
        getline(inp, curr, ',');
        
        auto root = new TreeNode(stoi(curr));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            for(int i = 0; i < 2; i++){
                getline(inp, curr, ',');
                if(curr != "#"){
                    auto node = new TreeNode(stoi(curr));
                    if(!i) q.front() -> left = node;
                    else q.front() -> right = node;
                    q.push(node);
                }
            }
            q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));