class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n + 1, 0), ans(n+1, 0);
        
        for(int i = n - 1; i >= 0; i--){
            dp[i+1] = q[i][0] + (i + q[i][1]+ 2 <= n ? ans[i + q[i][1]+ 2]: 0);
            ans[i+1] = max(dp[i+1], i+2 <= n ? ans[i+2]: 0);
            // for(int i: dp)
            //     cout << i << ",";
            // cout << endl;
        }
        return ans[1];
    }
};