class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        
        for(int idx = 0; idx < n; idx++){
            for(int prev = 0; prev < idx; prev++){
                if(a[prev] < a[idx]){
                    if(dp[prev] + 1 > dp[idx]){
                        dp[idx] = dp[prev]+ 1;
                        cnt[idx] = cnt[prev];
                    }
                    else if(dp[prev] + 1 == dp[idx]){
                        cnt[idx] += cnt[prev];
                    }
                }
            }
        }
        int ans1 = INT_MIN, ans2 = 0;
        for(int i = 0; i < n;i++){
            if(dp[i] > ans1){
                ans1 = dp[i];
                ans2 = cnt[i];
            }
            else if(dp[i] == ans1){
                ans2 += cnt[i];
            }
        }
        return ans2;
    }
};