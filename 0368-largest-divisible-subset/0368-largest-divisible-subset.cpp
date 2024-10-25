class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int> dp(n, 1), cameFrom(n, -1);
        for(int idx = 1; idx < n; idx++){
            for(int prev_idx = 0; prev_idx < idx; prev_idx++){
                if((a[idx] % a[prev_idx] == 0) && dp[idx] < dp[prev_idx] + 1){
                    dp[idx] = dp[prev_idx] + 1;
                    cameFrom[idx] = prev_idx;
                }
            }
        }
        int maxIdx = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> ans;
        while(maxIdx != -1){
            ans.push_back(a[maxIdx]);
            maxIdx = cameFrom[maxIdx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};