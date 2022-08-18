class Solution {
public:
    int f(vector<int> &c, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        for(int k = i; k <= j; k++ ){
                int tmp = f(c, i, k-1, dp) + f(c, k+1, j, dp) + c[j+1] - c[i-1];
                ans = min(tmp, ans);
        }
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c  = cuts.size();
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(c+1, vector<int>(c+1 , -1));
        return f(cuts, 1 , c, dp);
    }
};