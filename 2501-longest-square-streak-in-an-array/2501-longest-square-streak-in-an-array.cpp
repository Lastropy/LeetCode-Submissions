class Solution {
public:
    int longestSquareStreak(vector<int>& a) {
        sort(a.begin(), a.end());
        //  [2, 3, 4, 6, 8, 16]
        //  [1, 1, 1, 1, 1, 1]
        unordered_map<long long, int> mp;
        int n = a.size();
        for(int i = n - 1; i >= 0; i--){
            if(i != n - 1 && mp.count(1LL * a[i] * a[i])){
                mp[a[i]] = mp[1LL * a[i] * a[i]] + 1;
            }
            if(!mp.count(a[i])) mp[a[i]] = 1;
        }
        int ans = -1;
        for(auto [k, v]: mp){
            if(v >= 2 ){
                ans = max(v, ans);
            }
        }
        return ans;
    }
};