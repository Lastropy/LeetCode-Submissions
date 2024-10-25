class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1);
        for(int idx = 0; idx < n; idx++){
           for(int prev_idx = 0; prev_idx < idx; prev_idx++){
               if(a[idx] > a[prev_idx]){
                   dp[idx] = max(dp[idx], 1 + dp[prev_idx]);
               }
           }
        }
        return *max_element(dp.begin(), dp.end());
    }
};