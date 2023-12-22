class Solution {
public:
    int minSizeSubarray(vector<int>& a, int target) {
        int n = a.size();
        long long sum = accumulate(a.begin(), a.end(), 0* 1LL);
        int curr_len = (target / sum) * n;
        int left = target % sum;
        if(left == 0) return curr_len;
        for(int i = 0; i < n; i++) a.push_back(a[i]);
        long long pref  = 0;
        int ans = n + 1;
        for(int i = 0, j = 0; j < 2*n; j++){
            pref += a[j];
            while(left < pref) pref -= a[i++];
            if(left == pref ) ans = min(ans, j - i + 1);
        }
        return ans == n + 1 ? -1: ans+curr_len;
    }
};