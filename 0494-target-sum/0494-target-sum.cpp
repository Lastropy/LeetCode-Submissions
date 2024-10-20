class Solution {
public:
    map<pair<int, int>, int> dp;
    int solve(vector<int>& a, int idx, int t) {
        if(idx == a.size()){
            return (t == 0);
        }
        pair<int, int> p = {idx, t};
        if(dp.count(p)) return dp[p];
        int notTake = solve(a, idx + 1, t);
        int take = 0;
        if(t >= a[idx]) take = solve(a, idx + 1, t - a[idx]);
        return dp[p] = take + notTake;
    }
    
    int findTargetSumWays(vector<int>& a, int t) {
        int totalSum = accumulate(a.begin(), a.end(), 0);
        if((totalSum + t) % 2) return 0;
        int tar = (totalSum + t) / 2;
        return solve(a, 0, tar);
     }
};