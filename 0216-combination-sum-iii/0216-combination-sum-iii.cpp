class Solution {
public:
    void solve( vector<vector<int>> &ans, vector<int> &curr, int k, int t, int currDig = 1){
        if(k == curr.size()) {
            if(t == 0) ans.push_back(curr);     
            return;
        }
        if(currDig > 9) return;
        curr.push_back(currDig);
        solve(ans, curr, k, t - currDig, currDig + 1);
        curr.pop_back();
        solve(ans, curr, k, t, currDig + 1);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        if(9 * k < n || k > n) return ans;
        solve(ans, curr,k , n);
        return ans;
    }
};