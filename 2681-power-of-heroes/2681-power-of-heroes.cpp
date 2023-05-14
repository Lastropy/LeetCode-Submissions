class Solution {
public:
    int mod = 1e9 + 7;
    int sumOfPower(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        
        long long ans = 0;
        long long prev = 0;
        for(int ele: a){
            ans = (ans + ( prev + ele ) * ele % mod  * ele % mod) % mod;
            prev = (2*prev + ele) % mod;
        }
        return ans;
    }
};