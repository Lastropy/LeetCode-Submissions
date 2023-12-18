class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size(), ans = INT_MAX;
        deque<int> dq;
        
        vector<long> pref_sum(n + 1, 0);
        for(int i = 0; i < n; i++){
            pref_sum[i+1] = pref_sum[i] + a[i];
        }
        
        for(int i = 0; i <= n; i++){
            while(!dq.empty() && pref_sum[i] - pref_sum[dq.front()] >= k){
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            
            while(!dq.empty() && pref_sum[i] <= pref_sum[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        return ans == INT_MAX ? - 1: ans;
    }
};