class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k > n) return false;
        if(k == n) return true;
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;
        if(mp.size() <= k) return true;
        int eveners = 0, odders = 0;
        for(auto [k, v]: mp){
            if(v % 2 == 0) eveners++;
            else odders++;
        }
        return k >= odders;       
    }
};