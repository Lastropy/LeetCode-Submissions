class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<pair<TreeNode *,int>> q; 
        // vert -> {(lvl, value)};
        map<int, multiset<pair<int,int>>> mp;  
        q.push({root,0});

        for(int lvl = 0; !q.empty(); lvl++){
            for(int i = 0, size = q.size(); i < size; i++){
                auto vert = q.front().second;
                auto n = q.front().first;
                q.pop();
                mp[vert].insert({lvl, n -> val});
                if(n -> left) q.push({n -> left,vert -1});
                if(n -> right) q.push({n -> right,vert + 1});
            }
        }

        vector<int> temp;
        for(auto [vert,s]: mp){
            temp.clear();
            for(auto p: s)
                temp.push_back(p.second);
            ans.push_back(temp);
        }

        return ans;
    }
};