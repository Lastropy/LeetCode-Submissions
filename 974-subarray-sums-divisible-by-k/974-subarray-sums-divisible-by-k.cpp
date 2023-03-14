class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int mod[k];
        memset(mod,0,sizeof(mod));
        mod[0] = 1;
        int n = a.size(), ps = 0, ans = 0;
        for(int i = 0;i < n; i++){
            ps += a[i];
            ans += mod[(ps%k+k)%k]++;
        }
        return ans;
    }
};