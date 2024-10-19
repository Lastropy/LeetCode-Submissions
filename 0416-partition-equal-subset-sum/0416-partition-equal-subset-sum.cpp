class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int idx, int targetSum, vector<int>& a){
        if(targetSum == 0) return true;
        if(idx == a.size()) return false;
        if(dp[idx][targetSum] != -1) return dp[idx][targetSum];
        bool notTaken = solve(idx + 1, targetSum, a);
        bool taken = false;        
        if(a[idx] <= targetSum) taken = solve(idx + 1, targetSum - a[idx], a);
        return dp[idx][targetSum] = taken || notTaken;
    }
    
    bool canPartition(vector<int>& a) {
        int totalSum = 0;
        for(int i: a) totalSum += i;
        if(totalSum % 2) return false;
        int targetSum = (totalSum / 2);
        dp.resize(a.size(), vector<int>(targetSum + 1, -1));
        return solve(0, targetSum, a);
    }
};