class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1), hash(n, 1);
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(a[i] > a[prev] && dp[i] <= dp[prev] + 1){
                    if(dp[i] < dp[prev] + 1) hash[i] = 0;
                    hash[i] += hash[prev];
                    dp[i] = dp[prev] + 1;
                }
            }
        }
        
        int maxi = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi){
                ans += hash[i];
            }
        }
        return ans;
    }
};