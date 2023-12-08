class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int pref_diff_bw_1_n_0 = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            pref_diff_bw_1_n_0 += (a[i] == 1) - (a[i] == 0);
            if(mp.count(pref_diff_bw_1_n_0)) {
                ans = max(ans, i - mp[pref_diff_bw_1_n_0]);
            }
            else {
                mp[pref_diff_bw_1_n_0] = i;
            }
        }
        return ans;
    }
};