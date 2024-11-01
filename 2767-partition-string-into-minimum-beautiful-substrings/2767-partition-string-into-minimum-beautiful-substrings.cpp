class Solution {
public:
    vector<int> dp;
    int minimumBeautifulSubstrings(string s) {
        unordered_set<string> valid({"1", "101", "11001", "1111101", "1001110001", "110000110101", "11110100001001"});
        int n = s.size();
        dp.resize(n + 1, 1e9);
        dp[0] = 0;
        if(s[0] == '1') dp[1] = 1;
        for(int len = 2; len <= n; len++){
            for(int lastFix = 1; lastFix <= len; lastFix++){
                string fixed = s.substr(len - lastFix, lastFix);
                if(valid.find(fixed) != valid.end()){
                    dp[len] = min(dp[len], 1 + dp[len-lastFix]);
                }
            }
        }
        int ans = dp[n];
        if(ans >= 1e9) return -1;
        return ans;
    }
};