class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> next(n+1, 0);
        for(int idx = n-1; idx >= 0; idx--){
            vector<int> curr(n+1, 0);
            for(int prev_idx = idx - 1; prev_idx >= -1; prev_idx--){
                int notTake = 0 + next[prev_idx + 1];
                int take = 0;
                if(prev_idx == -1 || a[idx] > a[prev_idx]){
                    take = 1 + next[idx + 1];
                }
                curr[prev_idx + 1] = max(take, notTake);
            }
            next = curr;
        }
        return next[-1 + 1];
    }
};