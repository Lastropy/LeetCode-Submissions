class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &a, int idx, int t, vector<int> &curr){
        if(t == 0) {
            ans.push_back(curr);
            return;
        }
        if(t < 0 || idx == a.size()) return;
        
        curr.push_back(a[idx]);
        solve(ans, a, idx + 1, t - a[idx], curr);
        curr.pop_back();
        
        int skip = 1;
        while(skip + idx < a.size() && a[idx] == a[idx + skip])
            skip++;
        solve(ans, a, idx + skip, t, curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(ans, a, 0, t, curr);
        return ans;
    }
};