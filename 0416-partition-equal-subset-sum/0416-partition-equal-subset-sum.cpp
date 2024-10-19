class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int set1, int totalSum, int idx, vector<int>& a){
        if(idx == a.size()) {
            return (set1) == (totalSum - set1);
        }
        if(dp[idx][set1] != -1){
            return dp[idx][set1];
        }
        bool pos1 = solve(set1 + a[idx], totalSum, idx + 1, a);        
        bool pos2 = solve(set1, totalSum, idx + 1, a);
        return dp[idx][set1] = pos1 || pos2;
    }
    
    bool canPartition(vector<int>& a) {
        int totalSum = accumulate(a.begin(), a.end(), 0);
        dp.resize(a.size(), vector<int>(totalSum + 1, -1));
        return solve(0, totalSum, 0, a);
    }
};