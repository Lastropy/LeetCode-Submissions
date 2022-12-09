class Solution {
public:
    vector<int> min_max(TreeNode* root, int& res){
        if(!root) return {(int)1e5, (int)-1e5};
        
        auto ans1 = min_max(root -> left, res);
        auto ans2 = min_max(root -> right, res);
        
        int gmin = min({ans1[0], ans2[0]}), gmax = max({ans1[1], ans2[1]});
        if(gmin != 1e5)
            res = max(res, abs(gmin - (root -> val)));
        if(gmax != -1e5)
            res = max(res, abs(gmax - (root -> val)));
        // res = max(res, max({abs(gmin - (root -> val)), abs(gmax - (root -> val))}));
        // cout << (root -> val) << " ==> left == " << ans1[0] << " , " << ans1[1] << " |  right == " << ans2[0] << " , " << ans2[1] << " || res => " << res << endl; 
        auto ans = vector<int>({min(gmin, root -> val), max(gmax, root -> val)});
        return ans;
    }
    int maxAncestorDiff(TreeNode* root) {
        int res = -1e5;
        min_max(root, res);
        return res; 
    }
};