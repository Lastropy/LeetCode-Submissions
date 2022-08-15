class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());

        vector<int> dp(n, 1);

        vector<int> hash(n);

        int ans = INT_MIN;
        int curr_hash = 0;

        for(int i = 0; i < n; i++) hash[i] = i;

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(a[i] % a[prev] == 0){
                    if(dp[prev] + 1 > dp[i])  hash[i] = prev;
                    dp[i] = max(dp[i] , dp[prev] + 1);
                }
            }

            if(dp[i] > ans) curr_hash = i;
            ans = max(ans, dp[i]);
        }
    
        vector<int> res;
        int old_hash = -1;

        while(old_hash != curr_hash){
            res.push_back(a[curr_hash]);

            old_hash = curr_hash;
            curr_hash = hash[curr_hash];
        }
        
        reverse(begin(res), end(res));

        return res;
    }
};