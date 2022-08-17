class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        
        for(int idx = 0; idx < n; idx++){
            for(int prev = 0; prev < idx; prev++){

                if(a[prev] < a[idx] && dp[prev] + 1 >= dp[idx]){
					// if greater length LIS found, our current count of max length LIS is irrelevant now. Hence, reset to zero.
                    if(dp[prev] + 1 > dp[idx]) 
                        cnt[idx] = 0;

                    dp[idx] = dp[prev]+ 1;
                    cnt[idx] += cnt[prev];

                }
            }
        }

        int max_len = INT_MIN, count = 0;

        for(int i = 0; i < n;i++){

            if(dp[i] >= max_len){
				// Note the max length LIS. If greater Length LIS found, reset current count to zero.
                if(dp[i] > max_len) count = 0;

                max_len = dp[i];
                count += cnt[i];

            }
        }
        return count;
    }
};