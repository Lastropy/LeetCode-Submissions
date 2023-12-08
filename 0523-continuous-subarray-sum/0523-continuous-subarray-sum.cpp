class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int n = a.size();
        if(n < 2) return false;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int pref_sum = 0;
        for(int i = 0; i < n; i++){
            pref_sum += a[i];
            if(mp.count(pref_sum % k) && (i - mp[pref_sum % k]) >= 2) return true;
            else if(mp.count(pref_sum % k) == 0) mp[pref_sum % k] = i;
        }
        return false;
    }
};