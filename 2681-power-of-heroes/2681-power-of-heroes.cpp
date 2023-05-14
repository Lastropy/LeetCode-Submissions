class Solution {
public:
    int mod = 1e9 + 7;
    int sumOfPower(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        
        long long ans = 0;
        long long s = 0;
        for(int ele: a){
            ans = (ans + ( s + ele ) * ele % mod  * ele % mod) % mod;
            s = (2*s + ele) % mod;
        }
        return ans;
    }
};