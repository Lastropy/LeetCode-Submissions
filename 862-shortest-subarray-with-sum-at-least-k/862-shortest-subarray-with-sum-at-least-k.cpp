class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int ans = INT_MAX, n = a.size();
        if(n == 1) return a[0] >= k ? 1: -1;
        vector<long> pref_sum(n + 1, 0);
        for(int i = 1; i <= n; i++)
            pref_sum[i] = pref_sum[i-1] + a[i - 1];
        
        deque<int> dq;
        
        for(int j = 0; j <= n; j++){
            while(!dq.empty() && pref_sum[j] - pref_sum[dq.front()] >= k){
                ans = min(ans, j - dq.front());
                dq.pop_front();
            }
            
            
            while(!dq.empty() && pref_sum[j] <= pref_sum[dq.back()])
                dq.pop_back();
            dq.push_back(j);
        }
      
        return ans > n ? -1 : ans;
    }
};