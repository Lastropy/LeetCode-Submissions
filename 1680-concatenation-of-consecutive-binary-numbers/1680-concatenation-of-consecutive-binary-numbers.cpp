class Solution {
public:
    int mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        if(n == 1) return 1;
        int dig = log2(n) + 1;
        
        long long ans =  (n + ((1LL * concatenatedBinary(n-1) << dig) % mod))% mod;
        
        return ans;
    }
};