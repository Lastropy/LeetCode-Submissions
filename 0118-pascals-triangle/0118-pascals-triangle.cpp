class Solution {
public:
    int ncr(int n, int r) {
        int ans = 1;
        for(int i = 1; i <= r; i++){
            ans *= (n - i + 1);
            ans /= i;
        }
        return ans;
    }
    
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        for(int r = 1; r <= n; r++) {
            for(int c = 1; c <= r; c++) {
                ans[r - 1].push_back(ncr(r - 1, c - 1));
            }
        }
        return ans;
    }
};