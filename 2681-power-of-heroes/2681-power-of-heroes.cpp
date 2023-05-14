class Solution {
public:
    int mod = 1e9 + 7;
    int sumOfPower(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        
        long long ans = 0;
        long long s = 0;
        for(int l = 0; l < n; l++){
            ans = (ans + ( s + a[l]) * a[l] % mod  * a[l] % mod) % mod;
            s = (2*s + a[l]) % mod;
        }
        return ans;
    }
};