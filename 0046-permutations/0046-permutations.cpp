class Solution {
public:
    void solve(vector<vector<int>> &ans, unordered_map<int, int> &mp,        vector<int> &a, vector<int> &curr){
        if(curr.size() == a.size()) {
            ans.push_back(curr);
            return;
        }
        
        for(int i = 0; i < a.size(); i++){
            if(mp[a[i]] == 0) {
                mp[a[i]] = 1;
                curr.push_back(a[i]);
                solve(ans, mp, a, curr);
                mp[a[i]] = 0;
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        vector<int> curr;
        solve(ans, mp, a, curr);
        return ans;
    }
};