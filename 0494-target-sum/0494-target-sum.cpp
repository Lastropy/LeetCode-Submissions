class Solution {
public:
    int solve(vector<int>& a, int idx, int t) {
        if(idx == a.size()) return (t == 0);
        int add = solve(a, idx + 1, t + a[idx]);
        int subtract = solve(a, idx + 1, t - a[idx]);
        return add + subtract;
    }
    
    int findTargetSumWays(vector<int>& a, int t) {
        return solve(a, 0, t);
    }
};