class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size(), pref = 1, suff = 1;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
            pref *= a[i];
            suff *= a[n - i - 1];
            ans = max({ans, pref, suff});
        }
        return ans;
    }
};