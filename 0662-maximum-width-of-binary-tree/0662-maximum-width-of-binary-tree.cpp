class Solution {
public:
    int bfs(TreeNode* root){
        if(!root) return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});
        long long ans = 0, idx;
        while(!q.empty()){
            int siz = q.size();
            int mi = q.front().second, mx = q.back().second;
            ans = max(ans, 1LL * (mx - mi + 1));
            for(int i = 0; i < siz; i++){
                auto tmp = q.front(); q.pop();
                idx = tmp.second - mi;
                if(tmp.first -> left) q.push({tmp.first -> left, (idx * 2) + 1 });
                if(tmp.first -> right) q.push({tmp.first -> right, (idx * 2) + 2});
            }
        }
        return ans;
    }
    int widthOfBinaryTree(TreeNode* root) {
        return bfs(root);
    }
};