class Solution {
public:
    void dfs(TreeNode* r, map<int, vector<pair<int,int>>>& mp, int curr, int lvl){
        if(!r) return;
        
        mp[curr].push_back({lvl, r -> val});
        dfs(r -> left, mp, curr - 1, lvl+1);        
        dfs(r -> right, mp, curr + 1, lvl+1);        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* r) {
        map<int, vector<pair<int,int>>> mp;
        dfs(r, mp, 0, 0);
        
        vector<vector<int>> ans;
        for(auto [k,v]: mp){
            sort(v.begin(), v.end());
            ans.push_back({});
            for(auto p: v){
                ans.back().push_back(p.second);
            }
        }
        return ans;
    }
};