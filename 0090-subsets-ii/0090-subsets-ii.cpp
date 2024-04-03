class Solution {
public:
    void solve(vector<int> &a, vector<vector<int>> &ans, vector<int> &curr, int idx){
        if(idx == a.size()){
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(a[idx]);
        solve(a, ans, curr, idx + 1);
        
        curr.pop_back();
        int skip = 1;
        while(idx + skip < a.size() && a[idx + skip] == a[idx])
            skip++;
        solve(a, ans, curr, idx + skip);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(a, ans, curr, 0);
        return ans;
    }
};