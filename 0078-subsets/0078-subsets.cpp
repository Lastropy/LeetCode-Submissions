class Solution {
public:
    void generateSubsequences(vector<vector<int>> &ans, vector<int> &a, int idx, vector<int> &curr){
        if(idx == a.size()) {
            ans.push_back(curr);
            return;
        }
        
        generateSubsequences(ans, a, idx + 1, curr);
        curr.push_back(a[idx]);
        generateSubsequences(ans, a, idx + 1, curr);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int> curr;
        generateSubsequences(ans, a, 0,curr);
        return ans;
    }
};