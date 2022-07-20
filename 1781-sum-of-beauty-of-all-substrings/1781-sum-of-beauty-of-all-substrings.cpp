class Solution {
public:
    int leastFreq(unordered_map<char, int> &mp){
        int lf = INT_MAX;
        for(auto [k,v]: mp) if(v < lf) lf = v;
        return lf;
    }
    int beautySum(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            mp.clear();
            int mf = INT_MIN;
            for(int j = i ; j < s.size(); j++){
                mp[s[j]]++;
                mf = max(mf, mp[s[j]]);
                ans += mf - leastFreq(mp);
            }
        }
        return ans;
    }
};