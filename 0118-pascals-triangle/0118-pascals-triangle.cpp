class Solution {
public:    
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        for(int r = 1; r <= n; r++) {
            int ele = 1;
            ans[r - 1].push_back(ele);
            for(int c = 1; c < r; c++) {
                ele *= (r - c);
                ele /= c;
                ans[r - 1].push_back(ele);
            }
        }
        return ans;
    }
};