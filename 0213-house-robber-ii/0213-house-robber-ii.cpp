class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& a, int idx){
        if(idx >= a.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = a[idx] + solve(a, idx + 2);
        int skip = 0 + solve(a, idx + 1);
        return dp[idx] = max(take, skip);
    }
    
    int rob(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        dp.resize(n+1, -1);
        dp[n] = 0;
        int considerLastElement = solve(a, 1);
        int last = a.back(); a.pop_back();
        dp.clear();
        dp.resize(n+1, -1);
        dp[n] = 0;
        int considerFirstElement = solve(a, 0);
        a.push_back(last);
        // cout << considerFirstElement << " " << considerLastElement << endl;
        return max(considerFirstElement,considerLastElement);
    }
};