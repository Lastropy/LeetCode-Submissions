class Solution {
public:
    void generateCombos(vector<vector<int>> &ans, vector<int> &a, int idx, vector<int> &curr, int t){
        if(t < 0 || idx == a.size()) return;
        if(t == 0) {
            ans.push_back(curr);
            return;
        }
        
        generateCombos(ans, a, idx + 1, curr, t);
        curr.push_back(a[idx]);
        generateCombos(ans, a, idx, curr, t - a[idx]);
        curr.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<vector<int>> ans;
        vector<int> curr;
        generateCombos(ans, a, 0, curr, t);
        return ans;
    }
};