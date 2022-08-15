class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<int> dp(a.size(), 1);
        vector<int> hash(a.size());
        for(int i  = 0; i < hash.size(); i++)
            hash[i] = i;
        for(int i  = 0; i < a.size(); i++){
            for(int prev = 0; prev < i; prev++){
                if(a[prev] % a[i] == 0 || a[i] % a[prev] == 0){
                    if(dp[prev] + 1 > dp[i]){
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                }
            }
        }
        
        int ans = INT_MIN;
        int h = 0;
        for(int i = 0; i < dp.size(); i++){
            if(dp[i] > ans){
                ans = dp[i];
                h = i;
            }
        }
        vector<int> res;
        int old = -1;
        while(true){
            if(old == h) break;
            res.push_back(a[h]);
            old = h;
            h = hash[h];
        }
        
        reverse(begin(res), end(res));
        return res;
    }
};