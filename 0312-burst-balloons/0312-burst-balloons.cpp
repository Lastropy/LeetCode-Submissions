class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int> &a, int i, int j) {
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = -1e9;
        for(int k = i; k <= j; k++) {
            int part1 = solve(a, i, k - 1);
            int part2 = solve(a, k + 1, j);
            int curr = (a[i-1] * a[k] * a[j+1]);
            ans = max(ans, part1 + part2 + curr);
        }
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& a) {
        a.insert(a.begin() , 1);
        a.push_back(1);
        int n = a.size();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(a, 1, n - 2);
    }
};