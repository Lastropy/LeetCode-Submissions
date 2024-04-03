class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &a, int idx){
        if(idx == a.size()) {
            ans.push_back(a);
            return;
        }
        
        for(int i = idx; i < a.size(); i++){
            swap(a[idx], a[i]);
            solve(ans, a, idx + 1);
            swap(a[idx], a[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> ans;
        solve(ans, a, 0);
        return ans;
    }
};