class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pref_sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            pref_sum += a[i];
            if(mp.count(pref_sum - k))
                ans += mp[pref_sum - k];
            mp[pref_sum]++;
        }
        return ans;
    }
};